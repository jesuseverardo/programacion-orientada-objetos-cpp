#include <iomanip>
#include <iostream>
#include <string>
#include <utility>

class ClienteCfe {
public:
    ClienteCfe(std::string nombre = {}, std::string servicio = {}, int consumo = 0)
        : nombre_(std::move(nombre)), servicio_(std::move(servicio)),
          consumo_(consumo) {}

    bool leer() {
        std::cout << "Nombre del usuario: ";
        std::getline(std::cin >> std::ws, nombre_);
        std::cout << "Numero de servicio: ";
        std::getline(std::cin >> std::ws, servicio_);
        std::cout << "Consumo del periodo en kWh: ";
        return static_cast<bool>(std::cin >> consumo_) && consumo_ >= 0;
    }

    [[nodiscard]] double subtotal() const {
        constexpr double tarifaBasica = 0.933;
        constexpr double tarifaIntermedia = 1.139;
        constexpr double tarifaExcedente = 3.326;

        if (consumo_ <= 150) {
            return consumo_ * tarifaBasica;
        }
        if (consumo_ <= 280) {
            return 150.0 * tarifaBasica
                + (consumo_ - 150.0) * tarifaIntermedia;
        }
        return 150.0 * tarifaBasica + 130.0 * tarifaIntermedia
            + (consumo_ - 280.0) * tarifaExcedente;
    }

    void imprimir() const {
        constexpr double tasaIva = 0.16;
        const double importe = subtotal();
        const double iva = importe * tasaIva;

        std::cout << std::fixed << std::setprecision(2)
                  << "Nombre: " << nombre_ << '\n'
                  << "Numero de servicio: " << servicio_ << '\n'
                  << "Consumo: " << consumo_ << " kWh\n"
                  << "Subtotal: $" << importe << '\n'
                  << "IVA: $" << iva << '\n'
                  << "Total: $" << importe + iva << '\n';
    }

private:
    std::string nombre_;
    std::string servicio_;
    int consumo_;
};

int main() {
    ClienteCfe cliente;
    if (!cliente.leer()) {
        std::cerr << "El consumo debe ser un entero no negativo.\n";
        return 1;
    }
    cliente.imprimir();
    return 0;
}

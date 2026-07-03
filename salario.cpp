#include <algorithm>
#include <iostream>
#include <string>
#include <utility>

class Empleado {
public:
    Empleado(double pagoHora = 0.0, std::string nombre = {}, int horas = 0)
        : pagoHora_(pagoHora), nombre_(std::move(nombre)), horas_(horas) {}

    bool leer() {
        std::cout << "Nombre: ";
        std::getline(std::cin >> std::ws, nombre_);
        std::cout << "Pago por hora: ";
        if (!(std::cin >> pagoHora_) || pagoHora_ < 0.0) {
            return false;
        }
        std::cout << "Horas trabajadas en la semana: ";
        return static_cast<bool>(std::cin >> horas_) && horas_ >= 0;
    }

    [[nodiscard]] int horasNormales() const { return std::min(horas_, 40); }
    [[nodiscard]] int horasExtra() const { return std::max(horas_ - 40, 0); }
    [[nodiscard]] double salarioNormal() const { return pagoHora_ * horasNormales(); }
    [[nodiscard]] double salarioExtra() const { return 2.0 * pagoHora_ * horasExtra(); }
    [[nodiscard]] double salarioTotal() const { return salarioNormal() + salarioExtra(); }

    void imprimir() const {
        std::cout << "Nombre: " << nombre_ << '\n'
                  << "Horas normales: " << horasNormales() << '\n'
                  << "Horas extra: " << horasExtra() << '\n'
                  << "Salario normal: " << salarioNormal() << '\n'
                  << "Salario extra: " << salarioExtra() << '\n'
                  << "Salario total: " << salarioTotal() << '\n';
    }

private:
    double pagoHora_;
    std::string nombre_;
    int horas_;
};

int main() {
    Empleado empleado;
    if (!empleado.leer()) {
        std::cerr << "Datos de salario no validos.\n";
        return 1;
    }
    empleado.imprimir();
    return 0;
}

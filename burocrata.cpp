#include <iostream>
#include <string>
#include <utility>

class Burocrata {
public:
    Burocrata(std::string nombre = {}, double sueldoBruto = 0.0)
        : nombre_(std::move(nombre)), sueldoBruto_(sueldoBruto) {}

    bool leer() {
        std::cout << "Nombre del burocrata: ";
        std::getline(std::cin >> std::ws, nombre_);

        std::cout << "Sueldo bruto del burocrata: ";
        return static_cast<bool>(std::cin >> sueldoBruto_) && sueldoBruto_ >= 0.0;
    }

    [[nodiscard]] double calcularSueldoNeto() const {
        constexpr double factorNeto = 0.80;
        return sueldoBruto_ * factorNeto;
    }

    void imprimir() const {
        std::cout << "Nombre: " << nombre_ << '\n'
                  << "Sueldo neto: " << calcularSueldoNeto() << '\n';
    }

private:
    std::string nombre_;
    double sueldoBruto_;
};

int main() {
    Burocrata burocrata;
    if (!burocrata.leer()) {
        std::cerr << "Datos de sueldo no validos.\n";
        return 1;
    }
    burocrata.imprimir();
    return 0;
}

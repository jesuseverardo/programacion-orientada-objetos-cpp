#include <iostream>

class Empleado {
public:
    Empleado(int numero = 0, double salario = 0.0)
        : numero_(numero), salario_(salario) {}

    bool leer() {
        std::cout << "Numero de empleado: ";
        if (!(std::cin >> numero_) || numero_ < 0) {
            return false;
        }

        std::cout << "Salario del empleado: ";
        return static_cast<bool>(std::cin >> salario_) && salario_ >= 0.0;
    }

    void imprimir() const {
        std::cout << "Numero de empleado: " << numero_ << '\n'
                  << "Salario del empleado: " << salario_ << '\n';
    }

private:
    int numero_;
    double salario_;
};

int main() {
    Empleado empleado;
    if (!empleado.leer()) {
        std::cerr << "Datos de empleado no validos.\n";
        return 1;
    }
    empleado.imprimir();
    return 0;
}

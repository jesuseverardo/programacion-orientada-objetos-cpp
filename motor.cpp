#include <cmath>
#include <iostream>

class MotorAc {
public:
    MotorAc(double voltaje = 0.0, double potenciaHp = 0.0,
            double factorPotencia = 0.0)
        : voltaje_(voltaje), potenciaHp_(potenciaHp),
          factorPotencia_(factorPotencia) {}

    bool leer() {
        std::cout << "Voltaje de linea: ";
        if (!(std::cin >> voltaje_) || voltaje_ <= 0.0) {
            return false;
        }
        std::cout << "Potencia del motor (hp): ";
        if (!(std::cin >> potenciaHp_) || potenciaHp_ < 0.0) {
            return false;
        }
        std::cout << "Factor de potencia (0 a 1]: ";
        return static_cast<bool>(std::cin >> factorPotencia_)
            && factorPotencia_ > 0.0 && factorPotencia_ <= 1.0;
    }

    [[nodiscard]] double corriente() const {
        constexpr double wattsPorHp = 746.0;
        constexpr double factorCarga = 1.25;
        return factorCarga * potenciaHp_ * wattsPorHp
            / (std::sqrt(3.0) * voltaje_ * factorPotencia_);
    }

    void imprimir() const {
        std::cout << "Corriente estimada del motor: " << corriente() << " A\n";
    }

private:
    double voltaje_;
    double potenciaHp_;
    double factorPotencia_;
};

int main() {
    MotorAc motor;
    if (!motor.leer()) {
        std::cerr << "Datos del motor no validos.\n";
        return 1;
    }
    motor.imprimir();
    return 0;
}

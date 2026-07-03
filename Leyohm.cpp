#include <iostream>

class LeyOhm {
public:
    LeyOhm(double voltaje, double resistencia)
        : voltaje_(voltaje), resistencia_(resistencia) {}

    [[nodiscard]] double corriente() const {
        return voltaje_ / resistencia_;
    }

private:
    double voltaje_;
    double resistencia_;
};

int main() {
    double voltaje = 0.0;
    double resistencia = 0.0;

    std::cout << "Voltaje: ";
    if (!(std::cin >> voltaje)) {
        std::cerr << "Voltaje no valido.\n";
        return 1;
    }

    std::cout << "Resistencia: ";
    if (!(std::cin >> resistencia) || resistencia <= 0.0) {
        std::cerr << "La resistencia debe ser mayor que cero.\n";
        return 1;
    }

    const LeyOhm circuito(voltaje, resistencia);
    std::cout << "Corriente: " << circuito.corriente() << " A\n";
    return 0;
}

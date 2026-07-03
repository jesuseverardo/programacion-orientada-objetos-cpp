#include <iostream>

constexpr double PI = 3.14159265358979323846;

class Circulo {
public:
    explicit Circulo(double radio = 0.0) : radio_(radio) {}

    bool leer() {
        std::cout << "Radio del circulo: ";
        return static_cast<bool>(std::cin >> radio_) && radio_ >= 0.0;
    }

    [[nodiscard]] double perimetro() const { return 2.0 * PI * radio_; }
    [[nodiscard]] double area() const { return PI * radio_ * radio_; }

    void imprimir() const {
        std::cout << "Perimetro: " << perimetro() << '\n'
                  << "Area: " << area() << '\n';
    }

private:
    double radio_;
};

int main() {
    Circulo circulo;
    if (!circulo.leer()) {
        std::cerr << "El radio debe ser un numero no negativo.\n";
        return 1;
    }
    circulo.imprimir();
    return 0;
}

#include <iostream>

class Rectangulo {
public:
    Rectangulo(double largo, double ancho) : largo_(largo), ancho_(ancho) {}

    [[nodiscard]] double perimetro() const {
        return 2.0 * (largo_ + ancho_);
    }

    [[nodiscard]] double area() const {
        return largo_ * ancho_;
    }

private:
    double largo_;
    double ancho_;
};

int main() {
    const Rectangulo rectangulo(10.0, 5.0);
    std::cout << "Perimetro: " << rectangulo.perimetro() << '\n'
              << "Area: " << rectangulo.area() << '\n';
    return 0;
}

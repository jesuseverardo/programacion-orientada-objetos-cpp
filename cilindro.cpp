#include <iostream>

constexpr double PI = 3.14159265358979323846;

class Circulo {
public:
    explicit Circulo(double radio = 0.0) : radio_(radio) {}
    virtual ~Circulo() = default;

    bool leer() {
        std::cout << "Radio: ";
        return static_cast<bool>(std::cin >> radio_) && radio_ >= 0.0;
    }

    [[nodiscard]] double perimetro() const { return 2.0 * PI * radio_; }
    [[nodiscard]] double area() const { return PI * radio_ * radio_; }

    void imprimir() const {
        std::cout << "Perimetro del circulo: " << perimetro() << '\n'
                  << "Area del circulo: " << area() << '\n';
    }

protected:
    double radio_;
};

class Cilindro : public Circulo {
public:
    Cilindro(double radio = 0.0, double altura = 0.0)
        : Circulo(radio), altura_(altura) {}

    bool leer() {
        if (!Circulo::leer()) {
            return false;
        }
        std::cout << "Altura del cilindro: ";
        return static_cast<bool>(std::cin >> altura_) && altura_ >= 0.0;
    }

    [[nodiscard]] double volumen() const { return area() * altura_; }

    void imprimir() const {
        Circulo::imprimir();
        std::cout << "Volumen del cilindro: " << volumen() << '\n';
    }

private:
    double altura_;
};

int main() {
    Cilindro cilindro;
    if (!cilindro.leer()) {
        std::cerr << "El radio y la altura deben ser numeros no negativos.\n";
        return 1;
    }
    cilindro.imprimir();
    return 0;
}

#include <iostream>

class Complejo {
public:
    Complejo(double real = 0.0, double imaginario = 0.0)
        : real_(real), imaginario_(imaginario) {}

    bool leer() {
        char separador = '\0';
        std::cout << "Numero complejo en formato a,b: ";
        if (!(std::cin >> real_ >> separador >> imaginario_)) {
            return false;
        }
        return separador == ',';
    }

    void imprimir() const {
        std::cout << real_ << (imaginario_ < 0.0 ? " - " : " + ")
                  << (imaginario_ < 0.0 ? -imaginario_ : imaginario_) << 'i';
    }

    [[nodiscard]] Complejo operator+(const Complejo& otro) const {
        return {real_ + otro.real_, imaginario_ + otro.imaginario_};
    }

    [[nodiscard]] Complejo operator-(const Complejo& otro) const {
        return {real_ - otro.real_, imaginario_ - otro.imaginario_};
    }

    [[nodiscard]] Complejo operator*(const Complejo& otro) const {
        return {real_ * otro.real_ - imaginario_ * otro.imaginario_,
                real_ * otro.imaginario_ + imaginario_ * otro.real_};
    }

private:
    double real_;
    double imaginario_;
};

int main() {
    Complejo a;
    Complejo b;
    if (!a.leer() || !b.leer()) {
        std::cerr << "Formato no valido. Usa a,b; por ejemplo: 3,4.\n";
        return 1;
    }

    std::cout << "Suma: ";
    (a + b).imprimir();
    std::cout << "\nResta: ";
    (a - b).imprimir();
    std::cout << "\nMultiplicacion: ";
    (a * b).imprimir();
    std::cout << '\n';
    return 0;
}

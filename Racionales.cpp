#include <iostream>
#include <numeric>
#include <stdexcept>

class Racional {
public:
    Racional(int numerador = 0, int denominador = 1)
        : numerador_(numerador), denominador_(denominador) {
        normalizar();
    }

    bool leer() {
        char diagonal = '\0';
        std::cout << "Numero racional en formato a/b: ";
        if (!(std::cin >> numerador_ >> diagonal >> denominador_)) {
            return false;
        }
        if (diagonal != '/' || denominador_ == 0) {
            return false;
        }
        normalizar();
        return true;
    }

    void imprimir() const {
        std::cout << numerador_ << '/' << denominador_;
    }

    [[nodiscard]] Racional operator+(const Racional& otro) const {
        return {numerador_ * otro.denominador_ + otro.numerador_ * denominador_,
                denominador_ * otro.denominador_};
    }

    [[nodiscard]] Racional operator-(const Racional& otro) const {
        return {numerador_ * otro.denominador_ - otro.numerador_ * denominador_,
                denominador_ * otro.denominador_};
    }

    [[nodiscard]] Racional operator*(const Racional& otro) const {
        return {numerador_ * otro.numerador_, denominador_ * otro.denominador_};
    }

    [[nodiscard]] Racional operator/(const Racional& otro) const {
        if (otro.numerador_ == 0) {
            throw std::domain_error("No se puede dividir entre cero");
        }
        return {numerador_ * otro.denominador_, denominador_ * otro.numerador_};
    }

private:
    void normalizar() {
        if (denominador_ == 0) {
            throw std::invalid_argument("El denominador no puede ser cero");
        }
        if (denominador_ < 0) {
            numerador_ = -numerador_;
            denominador_ = -denominador_;
        }
        const int divisor = std::gcd(numerador_, denominador_);
        numerador_ /= divisor;
        denominador_ /= divisor;
    }

    int numerador_;
    int denominador_;
};

int main() {
    Racional a;
    Racional b;
    if (!a.leer() || !b.leer()) {
        std::cerr << "Racional no valido o denominador igual a cero.\n";
        return 1;
    }

    std::cout << "Suma: ";
    (a + b).imprimir();
    std::cout << "\nResta: ";
    (a - b).imprimir();
    std::cout << "\nMultiplicacion: ";
    (a * b).imprimir();

    try {
        std::cout << "\nDivision: ";
        (a / b).imprimir();
    } catch (const std::domain_error& error) {
        std::cout << error.what();
    }
    std::cout << '\n';
    return 0;
}

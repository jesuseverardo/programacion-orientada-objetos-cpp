#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Alumno {
public:
    Alumno(std::string nombre = {}, int boleta = 0, double calificacion = 0.0)
        : nombre_(std::move(nombre)), boleta_(boleta),
          calificacion_(calificacion) {}

    bool leer() {
        std::cout << "Nombre del alumno: ";
        std::getline(std::cin >> std::ws, nombre_);
        std::cout << "Numero de boleta: ";
        if (!(std::cin >> boleta_) || boleta_ < 0) {
            return false;
        }
        std::cout << "Calificacion (0 a 10): ";
        return static_cast<bool>(std::cin >> calificacion_)
            && calificacion_ >= 0.0 && calificacion_ <= 10.0;
    }

    [[nodiscard]] double calificacion() const { return calificacion_; }

    void imprimir() const {
        std::cout << "Nombre: " << nombre_ << '\n'
                  << "Boleta: " << boleta_ << '\n'
                  << "Calificacion: " << calificacion_ << '\n';
    }

private:
    std::string nombre_;
    int boleta_;
    double calificacion_;
};

int main() {
    int cantidad = 0;
    std::cout << "Cantidad de alumnos: ";
    if (!(std::cin >> cantidad) || cantidad <= 0) {
        std::cerr << "La cantidad debe ser mayor que cero.\n";
        return 1;
    }

    std::vector<Alumno> alumnos(static_cast<std::size_t>(cantidad));
    double suma = 0.0;
    for (Alumno& alumno : alumnos) {
        if (!alumno.leer()) {
            std::cerr << "Datos de alumno no validos.\n";
            return 1;
        }
        suma += alumno.calificacion();
    }

    for (const Alumno& alumno : alumnos) {
        alumno.imprimir();
    }
    std::cout << "Promedio del grupo: " << suma / alumnos.size() << '\n';
    return 0;
}

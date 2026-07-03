#include <iostream>
#include <string>

struct Alumno {
    std::string nombre;
    int boleta;
};

void imprimir(const Alumno& alumno) {
    std::cout << "Nombre del alumno: " << alumno.nombre << '\n'
              << "Numero de boleta: " << alumno.boleta << '\n';
}

int main() {
    const Alumno alumno1{"Alumno Ejemplo Uno", 100000001};
    const Alumno alumno2{"Alumno Ejemplo Dos", 100000002};

    imprimir(alumno1);
    imprimir(alumno2);
    return 0;
}

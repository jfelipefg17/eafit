#include "persona.h"  // Incluye el archivo de cabecera persona.h

// Definición del constructor
Persona::Persona(const std::string &nombre, int edad) : nombre(nombre), edad(edad) {}

// Definición de los métodos getter
std::string Persona::getNombre() const {
    return nombre;
}

int Persona::getEdad() const {
    return edad;
}

// Definición de los métodos setter
void Persona::setNombre(const std::string &nombre) {
    this->nombre = nombre;
}

void Persona::setEdad(int edad) {
    this->edad = edad;
}

// Definición de la sobrecarga del operador <<
std::ostream& operator<<(std::ostream &out, const Persona &persona) {
    out << "Nombre: " << persona.nombre << ", Edad: " << persona.edad;
    return out;
}
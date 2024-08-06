#include "person.h"  // Incluye el archivo de cabecera persona.h

// Definición del constructor
Person::Person(const std::string &nombre, int edad) : nombre(nombre), edad(edad) {}

// Definición de los métodos getter
std::string Person::getNombre() const {
    return nombre;
}

int Person::getEdad() const {
    return edad;
}

// Definición de los métodos setter
void Person::setNombre(const std::string &nombre) {
    this->nombre = nombre;
}

void Person::setEdad(int edad) {
    this->edad = edad;
}

// Definición de la sobrecarga del operador <<
std::ostream& operator<<(std::ostream &out, const Person &persona) {
    out << "Nombre: " << persona.nombre << ", Edad: " << persona.edad;
    return out;
}

// Sobrecarga del operador >
bool Person::operator>(const Person &other) const {
    return this->edad > other.edad;
}

// Sobrecarga del operador <
bool Person::operator<(const Person &other) const {
    return this->edad < other.edad;
}

// Sobrecarga del operador ==
bool Person::operator==(const Person &other) const {
    return this->edad == other.edad;
}
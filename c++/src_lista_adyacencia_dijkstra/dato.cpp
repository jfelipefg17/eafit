#include "dato.h"

// Implementación del constructor
Dato::Dato(const std::string& newNombre) : nombre(newNombre) {};

// Implementación del getter
std::string Dato::getNombre() const { return nombre; }

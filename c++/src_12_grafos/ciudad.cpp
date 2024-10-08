#include "ciudad.h"

// Constructor
Ciudad::Ciudad(int id, const std::string& n, const std::string& p, bool a)
    : id(id), nombre(n), pais(p), tieneAeropuerto(a) {}

// Métodos getter
int Ciudad::getId() const { return id; }
const std::string& Ciudad::getNombre() const { return nombre; }
const std::string& Ciudad::getPais() const { return pais; }
bool Ciudad::getTieneAeropuerto() const { return tieneAeropuerto; }

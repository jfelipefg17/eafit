#include "data.h"

// Constructor
Data::Data(int d, int t) : distancia(d), duracion(t) {}

// Métodos Getter
int Data::getDistancia() const { return distancia; }
int Data::getDuracion() const { return duracion; }

// Métodos Setter
void Data::setDistancia(int d) { distancia = d; }
void Data::setDuracion(int t) { duracion = t; }

// Método para calcular la velocidad promedio
double Data::calcularVelocidadPromedio() const {
    // Evitar división por cero
    if (duracion == 0) return 0;

    // Convertir duración de minutos a horas
    double duracionHoras = duracion / 60.0;

    // Cálculo de la velocidad en km/h
    return distancia / duracionHoras;
}


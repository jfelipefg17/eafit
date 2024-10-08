#ifndef DATA_H
#define DATA_H

#include <string>

// Estructura que representa los datos de un vuelo entre las ciudades
struct Data{
    int distancia; // Distancia de vuelo en kilómetros
    int duracion;  // Duración del vuelo en minutos

    // Constructor
    Data(int d = 0, int t = 0);

    // Métodos Getter
    int getDistancia() const;
    int getDuracion() const;

    // Métodos Setter
    void setDistancia(int d);
    void setDuracion(int t);

    // Método para calcular la velocidad promedio
    double calcularVelocidadPromedio() const;
};

#endif // DATA_H

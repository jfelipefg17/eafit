#include "matrizAdyacencia.h"
#include <iostream>

// Función para probar la implementación de matriz de adyacencia y BFS
void probarMatrizAdyacencia() {
    std::cout << "Probando la implementación con matriz de adyacencia:" << std::endl;
    MatrizAdyacencia grafoMA;

    // Agregar ciudades
    grafoMA.agregarCiudad("Roma", "Italia", true);
    grafoMA.agregarCiudad("Londres", "Reino Unido", true);
    grafoMA.agregarCiudad("Paris", "Francia", true);
    grafoMA.agregarCiudad("Madrid", "España", true);
    grafoMA.agregarCiudad("Nueva York", "Estados Unidos", true);
    grafoMA.agregarCiudad("Tokio", "Japón", true);
    grafoMA.agregarCiudad("Medellín", "Colombia", true);
    grafoMA.agregarCiudad("Lima", "Peru", true);
    grafoMA.agregarCiudad("Cali", "Colombia", true);

    // Agregar vuelos
    try {
        grafoMA.agregarVuelo("Medellín", "Roma", 9377, 1024);
        grafoMA.agregarVuelo("Medellín", "Nueva York", 3833, 556);
        grafoMA.agregarVuelo("Nueva York", "Cali", 3700, 540);
        grafoMA.agregarVuelo("Cali", "Roma", 300, 55);
        grafoMA.agregarVuelo("Roma", "Nueva York", 6865, 759);
        grafoMA.agregarVuelo("Nueva York", "Tokio", 10845, 873);
        grafoMA.agregarVuelo("Tokio", "Madrid", 10755, 950);
        grafoMA.agregarVuelo("Madrid", "Roma", 1363, 150);
        grafoMA.agregarVuelo("Madrid", "Paris", 1052, 120);
        grafoMA.agregarVuelo("Paris", "Lima", 1052, 120);
        grafoMA.agregarVuelo("Lima", "Londres", 3000, 550);
        grafoMA.agregarVuelo("Londres", "Paris", 344, 47);
    } catch (const std::exception& e) {
        std::cerr << "Error al agregar vuelo: " << e.what() << std::endl;
    }

    // Imprimir la red de vuelos
    grafoMA.imprimirRedVuelos();

    // Realizar BFS desde Medellín
    std::cout<< std::endl << "BFS desde Medellín:" << std::endl;
    grafoMA.BFS("Medellín");
}

int main() {
    probarMatrizAdyacencia();
    return 0;
}

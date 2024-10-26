#ifndef MATRIZADYACENCIA_H
#define MATRIZADYACENCIA_H

#include <vector>
#include <unordered_map>
#include "data.h"
#include "ciudad.h"

// Implementación de un grafo utilzando una matriz de adyacencia
class MatrizAdyacencia {
    private:
        std::vector<Ciudad> ciudades;                         // Vector de ciudades
        std::vector<std::vector<Data*> > matrizAdyacencia;     // Matriz de adyacencia
        std::unordered_map<std::string, int> nombreCiudadAId; // Mapa de nombres de ciudades a sus IDs

    public:
        // Constructor y destructor
        MatrizAdyacencia();
        ~MatrizAdyacencia();

        // Métodos para agregar ciudades y vuelos (vértices y aristas)
        void agregarCiudad(const std::string& nombre, const std::string& pais, bool tieneAeropuerto);
        void agregarVuelo(const std::string& ciudadOrigen, const std::string& ciudadDestino, int distancia, int duracion);

        // Métodos para imprimir y recorrer el grafo
        void imprimirRedVuelos() const;
        void BFS(const std::string& inicioCiudad) const;
};

#endif // MATRIZADYACENCIA_H

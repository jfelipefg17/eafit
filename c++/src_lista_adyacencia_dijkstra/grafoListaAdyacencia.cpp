#include "grafoListaAdyacencia.h"
#include <queue>

#include <iostream>

// Implementación del constructor
ListaAdyacencia::ListaAdyacencia() {}

// Implementación del destructor
ListaAdyacencia::~ListaAdyacencia() {}

// Implementación del getter
std::string ListaAdyacencia::getNodoInicio() const { return nodoInicio; }

// Implementación del setter
void ListaAdyacencia::insertarNodo(const std::string& nodo, const std::unordered_map<std::string, int>& vecinos) {
    listaAdyacencia[nodo] = vecinos;
}

// Implementación del setter
void ListaAdyacencia::setNodoInicio(const std::string& newNodoInicio) { nodoInicio = newNodoInicio; }

// Implementación método Dijkstra
void ListaAdyacencia::dijkstra(const std::string& nodoInicio) {
    // Cola de prioridad llamada cola
    std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, std::greater<std::pair<int, std::string>>> cola;
    // Inserción del nodoInicio en la cola
    cola.push(std::make_pair(0, nodoInicio));
    // Inserción del nodoInicio en el diccionario de padres
    padres[nodoInicio] = "Nadie";
    // Inserción del nodoInicio en el diccionario de costos
    costos[nodoInicio] = 0;

    // Mientras la cola no esté vacía
    while (cola.empty() != true) {
        // Extracción del primer elemento de la cola
        std::pair<int, std::string> actual = cola.top();
        cola.pop();
        // Extracción del costo actual
        int costoActual = actual.first;
        // Extracción del nombre del nodo actual
        std::string nodoActual = actual.second;
        // Iterar sobre los vecinos de nodoActual
        for (const auto& par : listaAdyacencia[nodoActual]) {
            // Extraer a vecino de par
            std::string vecino = par.first;
            // Extraer el costo de par
            int costo = par.second;
            // Instancia de un nuevo costo usando costo del nodoActual mas costo
            int nuevoCosto = costoActual + costo;
            // Si el vecino no está en el diccionario de costos o tiene un costo menor
            if (costos.find(vecino) == costos.end() || nuevoCosto < costos[vecino]) {
                // Actualizar el padre del vecino
                padres[vecino] = nodoActual;
                // Actualizar el costo del vecino
                costos[vecino] = nuevoCosto;
                // Inserción del vecino en la cola
                cola.push({nuevoCosto, vecino});
            }
        }
    }
}

// Implementación método para mostrar la lista de adyacencia
void ListaAdyacencia::mostrarListaAdyacencia() const {
    // Iteración por las nodos de listaAdyacencia
    for (const auto& nodos : listaAdyacencia) {
        std::cout << "Nodo: " << nodos.first << std::endl;
        // Iteración por los pares de nodos y valor de listaAdyacencia
        for (const auto& par : nodos.second) {
            std::cout << "  Vecino: " << par.first << ", Costo: " << par.second << std::endl;
        }
    }
}

// Implementación para mostrar padres
void ListaAdyacencia::mostrarPadres() const {
    std::cout << "Padres:" << std::endl;
    for (const auto& par : padres) {
        std::cout << "  " << par.first << ": " << par.second << std::endl;
    }
}

// Implementación para mostrar los costos
void ListaAdyacencia::mostrarCostos() const {
    std::cout << "Costos:" << std::endl;
    for (const auto& par : costos) {
        std::cout << "  " << par.first << ": " << par.second << std::endl;
    }
}

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include <utility>

// Clase para representar el grafo como una lista de adyacencia
class Grafo {
public:
    Grafo(int numVertices);
    void agregarArista(int origen, int destino, int peso);
    const std::vector<std::vector<std::pair<int, int>>>& obtenerListaAdyacencia() const;

private:
    std::vector<std::vector<std::pair<int, int>>> listaAdyacencia;
};

// Clase para implementar el algoritmo de Dijkstra
class Dijkstra {
public:
    Dijkstra(const Grafo& grafo);
    std::vector<int> encontrarCaminoMasCorto(int inicio, int final);

private:
    const Grafo& grafo;
};

#endif
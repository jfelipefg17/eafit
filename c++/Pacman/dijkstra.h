#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include <utility>  // Para std::pair

// Clase para representar el grafo como una lista de adyacencia
class Grafo {
public:
    Grafo(int filas, int columnas);
    void agregarArista(int origenX, int origenY, int destinoX, int destinoY, int peso);
    int obtenerIndice(int x, int y) const;
    const std::vector<std::vector<std::pair<int, int>>>& obtenerListaAdyacencia() const;
    int obtenerColumnas() const { return columnas; } // Método de acceso para `columnas`

private:
    int columnas;
    std::vector<std::vector<std::pair<int, int>>> listaAdyacencia;
};

// Clase para implementar el algoritmo de Dijkstra
class Dijkstra {
public:
    Dijkstra(const Grafo& grafo);
    std::vector<std::pair<int, int>> encontrarCaminoMasCorto(int inicioX, int inicioY, int finalX, int finalY);

private:
    const Grafo& grafo;
};

#endif

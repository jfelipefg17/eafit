#include "dijkstra.h"
#include <queue>
#include <vector>
#include <limits>

// Constructor del grafo
Grafo::Grafo(int filas, int columnas) : columnas(columnas) {
    listaAdyacencia.resize(filas * columnas);
}

// Convierte coordenadas 2D en un índice único
int Grafo::obtenerIndice(int x, int y) const {
    return x * columnas + y;
}

// Agrega una arista dirigida entre dos vértices
void Grafo::agregarArista(int origenX, int origenY, int destinoX, int destinoY, int peso) {
    int indiceOrigen = obtenerIndice(origenX, origenY);
    int indiceDestino = obtenerIndice(destinoX, destinoY);
    listaAdyacencia[indiceOrigen].emplace_back(indiceDestino, peso);
}

// Devuelve la lista de adyacencia
const std::vector<std::vector<std::pair<int, int>>>& Grafo::obtenerListaAdyacencia() const {
    return listaAdyacencia;
}

// Implementación de Dijkstra
Dijkstra::Dijkstra(const Grafo& grafo) : grafo(grafo) {}

std::vector<std::pair<int, int>> Dijkstra::encontrarCaminoMasCorto(int inicioX, int inicioY, int finalX, int finalY) {
    int inicioIdx = grafo.obtenerIndice(inicioX, inicioY);
    int finalIdx = grafo.obtenerIndice(finalX, finalY);

    int numVertices = grafo.obtenerListaAdyacencia().size();
    std::vector<int> dist(numVertices, std::numeric_limits<int>::max());
    std::vector<int> prev(numVertices, -1);
    dist[inicioIdx] = 0;

    typedef std::pair<int, int> Nodo;  // {distancia, nodo}
    std::priority_queue<Nodo, std::vector<Nodo>, std::greater<Nodo>> cola;
    cola.emplace(0, inicioIdx);

    while (!cola.empty()) {
        Nodo nodoSuperior = cola.top();
        int distActual = nodoSuperior.first;
        int u = nodoSuperior.second;
        cola.pop();

        if (u == finalIdx) break;

        for (size_t i = 0; i < grafo.obtenerListaAdyacencia()[u].size(); ++i) {
            int v = grafo.obtenerListaAdyacencia()[u][i].first;
            int peso = grafo.obtenerListaAdyacencia()[u][i].second;

            int nuevaDist = distActual + peso;
            if (nuevaDist < dist[v]) {
                dist[v] = nuevaDist;
                prev[v] = u;
                cola.emplace(nuevaDist, v);
            }
        }
    }

    // Reconstruir el camino
    std::vector<std::pair<int, int>> camino;
    for (int aux = finalIdx; aux != -1; aux = prev[aux]) {
        int x = aux / grafo.obtenerColumnas();
        int y = aux % grafo.obtenerColumnas();
        camino.insert(camino.begin(), std::make_pair(x, y));  // Insertar al principio
    }

    return camino;
}

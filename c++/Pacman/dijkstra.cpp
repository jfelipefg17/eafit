#include "dijkstra.h"
#include <queue>
#include <vector>
#include <limits>
#include <algorithm>
#include <cmath>

// Constructor de la clase Grafo que recibe el número de vértices
Grafo::Grafo(int numVertices) {
    listaAdyacencia.resize(numVertices); // Redimensiona la lista de adyacencia para manejar todos los vértices en el grafo
}

// Función para agregar una arista con peso entre dos vértices
void Grafo::agregarArista(int origen, int destino, int peso) {
    listaAdyacencia[origen].emplace_back(destino, peso); // Agrega el destino y el peso al vértice origen
    listaAdyacencia[destino].emplace_back(origen, peso); // Agrega el origen y el peso al vértice destino (grafo no dirigido)
}

// Devuelve la lista de adyacencia completa del grafo
const std::vector<std::vector<std::pair<int, int>>>& Grafo::obtenerListaAdyacencia() const {
    return listaAdyacencia;
}

// Constructor de la clase Dijkstra, que recibe un grafo para operar
Dijkstra::Dijkstra(const Grafo& grafo) : grafo(grafo) {}

// Encuentra el camino más corto entre dos puntos en el grafo, usando el algoritmo de Dijkstra
std::vector<int> Dijkstra::encontrarCaminoMasCorto(int inicio, int final) {
    int numVertices = grafo.obtenerListaAdyacencia().size();  // Cantidad total de vértices en el grafo
    std::vector<int> dist(numVertices, std::numeric_limits<int>::max());  // Vector de distancias inicializado en infinito
    std::vector<int> prev(numVertices, -1);                   // Vector para rastrear el camino, inicializado en -1
    dist[inicio] = 0;                                         // La distancia del nodo inicial a sí mismo es 0

    typedef std::pair<int, int> Nodo;   // Par (distancia, índice del nodo)
    std::priority_queue<Nodo, std::vector<Nodo>, std::greater<Nodo>> cola;  // Cola de prioridad para procesar nodos
    cola.emplace(0, inicio);            // Inserta el nodo inicial en la cola con distancia 0

    while (!cola.empty()) {             // Bucle hasta que todos los nodos sean procesados
        Nodo nodoSuperior = cola.top(); // Nodo con menor distancia en la cola
        int distActual = nodoSuperior.first;  // Distancia actual del nodo superior
        int u = nodoSuperior.second;          // Índice del nodo superior
        cola.pop();                           // Remueve el nodo superior de la cola

        if (u == final) break;                // Si llegamos al nodo final, terminamos la búsqueda

        for (const auto& vecino : grafo.obtenerListaAdyacencia()[u]) {  // Itera sobre los vecinos del nodo actual
            int v = vecino.first;    // Índice del vecino
            int peso = vecino.second;  // Peso de la arista entre u y v

            int nuevaDist = distActual + peso;    // Calcula la nueva distancia al vecino v
            if (nuevaDist < dist[v]) {            // Si la nueva distancia es menor, actualiza
                dist[v] = nuevaDist;              // Actualiza la distancia mínima para el vecino v
                prev[v] = u;                      // Actualiza el nodo previo para trazar el camino
                cola.emplace(nuevaDist, v);       // Inserta el vecino v en la cola con su nueva distancia
            }
        }
    }

    std::vector<int> camino;  // Vector para almacenar el camino desde el inicio hasta el final
    for (int aux = final; aux != -1; aux = prev[aux]) {  // Rastrear desde el nodo final al nodo inicial usando `prev`
        camino.insert(camino.begin(), aux); // Inserta el nodo en el camino al inicio del vector
    }

    return camino;  // Retorna el camino calculado en términos de índices de vértices
}
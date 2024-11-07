#include "dijkstra.h"            // Incluye el archivo de cabecera "dijkstra.h"
#include <queue>                 // Incluye la librería para la estructura de cola de prioridad
#include <vector>                // Incluye la librería para usar vectores
#include <limits>                // Incluye la librería para manejar valores límites (como infinito)
#include <algorithm>             // Incluye la librería para operaciones como std::sort
#include <cmath>                 // Incluye la librería para funciones matemáticas, como std::abs

// Constructor de la clase Grafo que recibe filas y columnas y define el tamaño del tablero
Grafo::Grafo(int filas, int columnas) : columnas(columnas) {
    listaAdyacencia.resize(filas * columnas); // Redimensiona la lista de adyacencia para manejar todos los vértices en el grafo
}

// Función que convierte coordenadas (x, y) en un índice único para el tablero
int Grafo::obtenerIndice(int x, int y) const {
    return x * columnas + y;      // Calcula el índice de la celda (x, y) en el vector unidimensional
}

// Función para agregar una arista con peso entre dos vértices dados en coordenadas (x, y)
void Grafo::agregarArista(int origenX, int origenY, int destinoX, int destinoY, int peso) {
    int indiceOrigen = obtenerIndice(origenX, origenY);   // Obtiene el índice del vértice origen
    int indiceDestino = obtenerIndice(destinoX, destinoY); // Obtiene el índice del vértice destino
    listaAdyacencia[indiceOrigen].emplace_back(indiceDestino, peso); // Agrega el destino y el peso al vértice origen
}

// Devuelve la lista de adyacencia completa del grafo
const std::vector<std::vector<std::pair<int, int>>>& Grafo::obtenerListaAdyacencia() const {
    return listaAdyacencia;
}

// Función que genera aristas hacia los tres vértices más cercanos en términos de distancia Manhattan
void Grafo::generarAristasCercanas() {
    int filas = listaAdyacencia.size() / columnas;   // Calcula la cantidad de filas del tablero

    for (int x = 0; x < filas; ++x) {                // Recorre cada celda en las filas
        for (int y = 0; y < columnas; ++y) {         // Recorre cada celda en las columnas
            std::vector<std::pair<int, std::pair<int, int>>> distancias;  // Vector para almacenar distancias a otros vértices

            // Calcula la distancia Manhattan a todos los demás vértices
            for (int i = 0; i < filas; ++i) {
                for (int j = 0; j < columnas; ++j) {
                    if (i != x || j != y) {          // Asegura que no calcule la distancia consigo mismo
                        int distancia = std::abs(x - i) + std::abs(y - j);  // Distancia Manhattan
                        distancias.push_back({distancia, {i, j}});          // Agrega la distancia y las coordenadas destino
                    }
                }
            }

            // Ordena las distancias para encontrar los tres vértices más cercanos
            std::sort(distancias.begin(), distancias.end());
            for (int k = 0; k < 3 && k < distancias.size(); ++k) {  // Selecciona los tres más cercanos
                int destinoX = distancias[k].second.first;          // Coordenada X del destino
                int destinoY = distancias[k].second.second;         // Coordenada Y del destino
                int peso = distancias[k].first;                     // Usa la distancia como peso
                agregarArista(x, y, destinoX, destinoY, peso);      // Agrega la arista entre los vértices
            }
        }
    }
}

// Constructor de la clase Dijkstra, que recibe un grafo para operar
Dijkstra::Dijkstra(const Grafo& grafo) : grafo(grafo) {}

// Encuentra el camino más corto entre dos puntos en el tablero, usando el algoritmo de Dijkstra
std::vector<std::pair<int, int>> Dijkstra::encontrarCaminoMasCorto(int inicioX, int inicioY, int finalX, int finalY) {
    int inicioIdx = grafo.obtenerIndice(inicioX, inicioY);  // Obtiene el índice del nodo inicial
    int finalIdx = grafo.obtenerIndice(finalX, finalY);     // Obtiene el índice del nodo final

    int numVertices = grafo.obtenerListaAdyacencia().size();  // Cantidad total de vértices en el grafo
    std::vector<int> dist(numVertices, std::numeric_limits<int>::max());  // Vector de distancias inicializado en infinito
    std::vector<int> prev(numVertices, -1);                   // Vector para rastrear el camino, inicializado en -1
    dist[inicioIdx] = 0;                                      // La distancia del nodo inicial a sí mismo es 0

    typedef std::pair<int, int> Nodo;   // Par (distancia, índice del nodo)
    std::priority_queue<Nodo, std::vector<Nodo>, std::greater<Nodo>> cola;  // Cola de prioridad para procesar nodos
    cola.emplace(0, inicioIdx);         // Inserta el nodo inicial en la cola con distancia 0

    while (!cola.empty()) {             // Bucle hasta que todos los nodos sean procesados
        Nodo nodoSuperior = cola.top(); // Nodo con menor distancia en la cola
        int distActual = nodoSuperior.first;  // Distancia actual del nodo superior
        int u = nodoSuperior.second;          // Índice del nodo superior
        cola.pop();                           // Remueve el nodo superior de la cola

        if (u == finalIdx) break;             // Si llegamos al nodo final, terminamos la búsqueda

        for (size_t i = 0; i < grafo.obtenerListaAdyacencia()[u].size(); ++i) {  // Itera sobre los vecinos del nodo actual
            int v = grafo.obtenerListaAdyacencia()[u][i].first;    // Índice del vecino
            int peso = grafo.obtenerListaAdyacencia()[u][i].second;  // Peso de la arista entre u y v

            int nuevaDist = distActual + peso;    // Calcula la nueva distancia al vecino v
            if (nuevaDist < dist[v]) {            // Si la nueva distancia es menor, actualiza
                dist[v] = nuevaDist;              // Actualiza la distancia mínima para el vecino v
                prev[v] = u;                      // Actualiza el nodo previo para trazar el camino
                cola.emplace(nuevaDist, v);       // Inserta el vecino v en la cola con su nueva distancia
            }
        }
    }

    std::vector<std::pair<int, int>> camino;  // Vector para almacenar el camino desde el inicio hasta el final
    for (int aux = finalIdx; aux != -1; aux = prev[aux]) {  // Rastrear desde el nodo final al nodo inicial usando `prev`
        int x = aux / grafo.obtenerColumnas();              // Calcula la coordenada X a partir del índice
        int y = aux % grafo.obtenerColumnas();              // Calcula la coordenada Y a partir del índice
        camino.insert(camino.begin(), std::make_pair(x, y)); // Inserta el nodo en el camino al inicio del vector
    }

    return camino;  // Retorna el camino calculado en términos de coordenadas (x, y)
}

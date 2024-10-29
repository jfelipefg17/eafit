#include "dijkstra.h"                       // Incluye el encabezado "dijkstra.h" donde se declara la función dijkstra
#include <vector>                           // Incluye la biblioteca para trabajar con vectores dinámicos
#include <queue>                            // Incluye la biblioteca para usar colas de prioridad
#include <limits>                           // Incluye la biblioteca para usar límites de tipo de datos
#include <iostream>                         // Incluye la biblioteca iostream para manejar operaciones de entrada y salida

// Función que convierte un número de nodo a su correspondiente letra (A, B, C, ...)
char obtenerLetra(int nodo) {
    return 'A' + nodo;                     // Convierte el número del nodo a su letra correspondiente
}

// Función que implementa el algoritmo de Dijkstra para encontrar el camino mínimo
void dijkstra(Graph* grafo, int origen, int destino) {
    // Vector que almacena la distancia mínima desde el nodo de origen a cada nodo
    std::vector<double> distancia(grafo->numNodos, std::numeric_limits<double>::infinity());
    // Vector que almacena el nodo predecesor de cada nodo en el camino más corto
    std::vector<int> predecesor(grafo->numNodos, -1);
    distancia[origen] = 0;                 // La distancia al nodo de origen es 0

    using Par = std::pair<double, int>;    // Define un par que contiene distancia y nodo
    std::priority_queue<Par, std::vector<Par>, std::greater<Par> > pq; // Cola de prioridad para seleccionar el nodo con la menor distancia
    pq.push(std::make_pair(0.0, origen));  // Inserta el nodo de origen en la cola con distancia 0

    // Bucle principal del algoritmo
    while (!pq.empty()) {
        auto [dist, u] = pq.top();          // Extrae el nodo con la menor distancia
        pq.pop();

        if (u == destino) break;            // Si se alcanza el nodo destino, salir del bucle

        // Recorre los arcos del nodo actual
        for (const auto& arco : grafo->adyacencia[u]) {
            double nuevoCosto = dist + arco.distancia * arco.dificultad; // Calcula el nuevo costo
            // Si el nuevo costo es menor que el costo conocido, actualizar
            if (nuevoCosto < distancia[arco.destino]) {
                distancia[arco.destino] = nuevoCosto; // Actualiza la distancia
                predecesor[arco.destino] = u;         // Establece el nodo predecesor
                pq.push(std::make_pair(nuevoCosto, arco.destino)); // Añade el nuevo nodo a la cola
            }
        }
    }

    // Si el destino es inalcanzable, informar al usuario
    if (distancia[destino] == std::numeric_limits<double>::infinity()) {
        std::cout << "No hay camino desde " << obtenerLetra(origen) << " a " << obtenerLetra(destino) << "." << std::endl;
        return;  // Salir de la función
    }

    // Reconstruir el camino a partir de los predecesores
    std::vector<int> camino;
    for (int at = destino; at != -1; at = predecesor[at]) { // Sigue el camino desde el destino hasta el origen
        camino.push_back(at);                          // Añade el nodo al camino
    }
    std::reverse(camino.begin(), camino.end()); // Revierte el camino para mostrarlo desde el origen hasta el destino

    // Mostrar el camino con detalles
    std::cout << "Camino de " << obtenerLetra(origen) << " a " << obtenerLetra(destino) << ": ";
    for (size_t i = 0; i < camino.size(); ++i) {
        std::cout << "\n" << obtenerLetra(camino[i]); // Muestra el nodo actual
        // Si no es el último nodo del camino
        if (i < camino.size() - 1) {
            int nodoActual = camino[i];              // Nodo actual
            int siguienteNodo = camino[i + 1];       // Siguiente nodo en el camino
            // Busca el arco entre el nodo actual y el siguiente nodo
            for (const auto& arco : grafo->adyacencia[nodoActual]) {
                if (arco.destino == siguienteNodo) { // Si el arco lleva al siguiente nodo
                    std::cout << " -> [" << "km: " << arco.distancia << " , dif: " << arco.dificultad << "] -> " << obtenerLetra(siguienteNodo);
                    break; // Salir del bucle después de encontrar el arco
                }
            }
        }
    }
    // Mostrar el costo total del camino
    std::cout << "\nCosto total: " << distancia[destino] << std::endl;
}

#ifndef DIJKSTRA_H  // Verifica si DIJKSTRA_H no ha sido definido
#define DIJKSTRA_H  // Define DIJKSTRA_H para evitar inclusiones múltiples

#include "grafo.h"  // Incluye el encabezado "grafo.h" donde se definen las estructuras y funciones relacionadas con el grafo

// Declaración de la función dijkstra, que calcula el camino mínimo en el grafo
void dijkstra(Graph* grafo, int origen, int destino); // Recibe un puntero al grafo, el nodo de origen y el nodo de destino

#endif  // Fin de la protección de inclusión

#ifndef GRAFO_H
#define GRAFO_H

#include <vector>  // Incluye la biblioteca para trabajar con vectores dinámicos

// Estructura que representa un arco (conexión) entre dos nodos en el grafo
typedef struct {
    int destino;       // Nodo al que se dirige el arco
    double distancia;  // Distancia entre el nodo de origen y el nodo de destino
    double dificultad; // Factor de dificultad del arco, que afecta el costo del trayecto
} Arc;

// Estructura que representa el grafo completo
typedef struct {
    int numNodos;                        // Número total de nodos en el grafo
    std::vector<std::vector<Arc> > adyacencia; // Lista de adyacencia, donde cada nodo tiene una lista de arcos
} Graph;

// Función que crea un grafo con un número específico de nodos
Graph* crearGrafo(int numNodos);

// Función que añade un arco al grafo entre dos nodos específicos
void agregarArco(Graph* grafo, int origen, int destino, double distancia, double dificultad);

// Función que libera la memoria asignada para el grafo
void liberarGrafo(Graph* grafo);

#endif  // Final de la protección de inclusión

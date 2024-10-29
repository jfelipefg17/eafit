#include "grafo.h"  // Incluye el encabezado "grafo.h" donde se definen las estructuras y funciones relacionadas con el grafo
#include <iostream> // Incluye la biblioteca iostream para manejar las operaciones de entrada y salida, aunque aquí no se usa

// Función que crea e inicializa un grafo con un número específico de nodos
Graph* crearGrafo(int numNodos) {
    Graph* grafo = new Graph;         // Asigna memoria para un nuevo grafo y devuelve un puntero a él
    grafo->numNodos = numNodos;       // Establece el número de nodos en el grafo
    grafo->adyacencia.resize(numNodos); // Redimensiona el vector de adyacencia para que tenga un vector vacío por cada nodo
    return grafo;                     // Devuelve el puntero al grafo recién creado
}

// Función que añade un arco al grafo entre dos nodos específicos
void agregarArco(Graph* grafo, int origen, int destino, double distancia, double dificultad) {
    Arc arco = {destino, distancia, dificultad}; // Crea un nuevo arco con el destino, distancia y dificultad especificados
    grafo->adyacencia[origen].push_back(arco);   // Añade el arco al vector de adyacencia del nodo de origen
}

// Función que libera la memoria asignada para el grafo
void liberarGrafo(Graph* grafo) {
    delete grafo;  // Libera la memoria del grafo para evitar fugas de memoria
}

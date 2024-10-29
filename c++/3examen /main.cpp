#include <iostream>                         // Incluye la biblioteca iostream para manejar operaciones de entrada y salida
#include "grafo.h"                          // Incluye el encabezado "grafo.h" donde se declaran las funciones para manejar el grafo
#include "dijkstra.h"                       // Incluye el encabezado "dijkstra.h" donde se declara la función dijkstra

// Función que inicializa el grafo con arcos y sus respectivas distancias y dificultades
void inicializarGrafo(Graph* grafo) {
    // Agrega arcos entre nodos con distancia y dificultad específica
    agregarArco(grafo, 0, 1, 30, 0.5);    // A -> B (30, fácil)
    agregarArco(grafo, 1, 2, 20, 1.6);    // B -> C (20, difícil)
    agregarArco(grafo, 1, 5, 50, 1.6);    // B -> F (50, difícil)
    agregarArco(grafo, 2, 3, 50, 1.0);    // C -> D (50, medio)
    agregarArco(grafo, 3, 4, 10, 1.6);    // D -> E (10, difícil)
    agregarArco(grafo, 3, 11, 200, 1.6);  // D -> L (200, difícil)
    agregarArco(grafo, 4, 5, 10, 0.5);    // E -> F (10, fácil)
    agregarArco(grafo, 5, 6, 40, 0.5);    // F -> G (40, fácil)
    agregarArco(grafo, 6, 7, 20, 1.0);    // G -> H (20, medio)
    agregarArco(grafo, 7, 0, 30, 1.0);    // H -> A (30, medio)
    agregarArco(grafo, 7, 8, 20, 1.6);    // H -> I (20, difícil)
    agregarArco(grafo, 8, 9, 40, 1.0);    // I -> J (40, medio)
    agregarArco(grafo, 9, 10, 30, 1.6);   // J -> K (30, difícil)
    agregarArco(grafo, 10, 11, 50, 0.5);  // K -> L (50, fácil)
    agregarArco(grafo, 10, 14, 10, 0.5);  // K -> O (10, fácil)
    agregarArco(grafo, 11, 12, 20, 1.6);  // L -> M (20, difícil)
    agregarArco(grafo, 12, 13, 20, 0.5);  // M -> N (20, fácil)
    agregarArco(grafo, 13, 14, 40, 1.0);  // N -> O (40, medio)
    agregarArco(grafo, 14, 15, 20, 1.0);  // O -> P (20, medio)
    agregarArco(grafo, 14, 8, 40, 0.5);   // O -> I (40, fácil)
    agregarArco(grafo, 15, 0, 100, 0.5);  // P -> A (100, fácil)
}

// Función que convierte una letra (A-P) a su correspondiente número (0-15)
int convertirLetraANumero(char letra) {
    return letra - 'A';                   // Resta 'A' de la letra para obtener su índice numérico
}

int main() {
    Graph* grafo = crearGrafo(16);       // Crea un grafo con 16 nodos
    inicializarGrafo(grafo);              // Inicializa el grafo con arcos y costos

    // Ciclo que permite realizar múltiples consultas de caminos mínimos
    for (int i = 0; i < 5; ++i) {
        char origenLetra, destinoLetra;   // Variables para almacenar las letras de origen y destino
        std::cout << "Ingrese la letra de origen (A-P): "; // Solicita la letra de origen
        std::cin >> origenLetra;           // Lee la letra de origen
        std::cout << "Ingrese la letra de destino (A-P): "; // Solicita la letra de destino
        std::cin >> destinoLetra;          // Lee la letra de destino

        // Convierte las letras a índices numéricos
        int origen = convertirLetraANumero(origenLetra);
        int destino = convertirLetraANumero(destinoLetra);

        // Verifica si las entradas son válidas
        if (origen < 0 || origen >= 16 || destino < 0 || destino >= 16) {
            std::cout << "Entrada no válida. Intente nuevamente." << std::endl; // Mensaje de error
            --i; // Decrementa i para repetir este intento
            continue; // Continúa con el siguiente ciclo
        }

        // Calcula y muestra el camino mínimo
        std::cout << "Calculando el camino mínimo de " << origenLetra << " a " << destinoLetra << "..." << std::endl;
        dijkstra(grafo, origen, destino);    // Llama a la función dijkstra para calcular el camino
    }

    liberarGrafo(grafo);                   // Libera la memoria del grafo
    return 0;                              // Retorna 0 indicando que el programa finalizó correctamente
}

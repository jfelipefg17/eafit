#include "dijkstra.h" // Incluye el archivo de cabecera con la implementación del grafo y Dijkstra
#include <iostream>   // Para entrada y salida estándar
#include <vector>     // Para usar el contenedor vector
#include <cstdlib>    // Para generación de números aleatorios
#include <ctime>      // Para usar time como semilla en la aleatoriedad
#include <cmath>      // Para cálculos matemáticos, como la raíz cuadrada
#include <thread>     // Para la funcionalidad de pausa con sleep_for
#include <chrono>     // Para especificar la duración de la pausa
#include <fstream>  // Para trabajar con archivos

// Función para imprimir el tablero en la consola y en un archivo
void imprimirTablero(const std::vector<std::vector<char>>& tablero, std::ofstream& archivo) {
    for (const auto& fila : tablero) {          // Recorre cada fila del tablero
        for (char celda : fila) {               // Recorre cada celda en la fila
            std::cout << celda << ' ';          // Imprime la celda con espacio
            archivo << celda << ' ';            // Escribe en el archivo también
        }
        std::cout << std::endl;                 // Salta a la siguiente línea al final de la fila
        archivo << std::endl;                   // Añade salto de línea en el archivo
    }
    archivo << "--------------------------------" << std::endl; // Separador en archivo
    std::cout << "--------------------------------" << std::endl;
}

// Limpia la pantalla para una mejor visualización del movimiento
void limpiarPantalla() {
    for (int i = 0; i < 50; ++i) std::cout << std::endl; // Imprime varias líneas en blanco
}

int main() {
    int filas, columnas;
    std::cout << "Ingresa el número de filas: ";
    std::cin >> filas;                             // Recibe número de filas para el tablero
    std::cout << "Ingresa el número de columnas: ";
    std::cin >> columnas;

    // Abre un archivo de salida
    std::ofstream archivo("salida.txt");// Recibe número de columnas para el tablero

    // Inicializa el tablero como una matriz de caracteres, lleno de '.'
    std::vector<std::vector<char>> tablero(filas, std::vector<char>(columnas, '.'));

    // Inicializa la semilla para generación de números aleatorios
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Calcula la cantidad de vértices usando la raíz cuadrada de n x m
    int numVertices = static_cast<int>(std::sqrt(filas * columnas));

    // Genera posiciones aleatorias para colocar los vértices en el tablero
    std::vector<std::pair<int, int>> vertices;
    while (vertices.size() < numVertices) {
        int x = std::rand() % filas;
        int y = std::rand() % columnas;
        if (tablero[x][y] == '.') {            // Asegura que la posición está libre antes de colocar un vértice
            vertices.emplace_back(x, y);       // Agrega la posición a la lista de vértices
            tablero[x][y] = 'F';               // Marca el vértice como un fantasma ('F')
        }
    }

    // Selecciona una posición aleatoria de los vértices para colocar a Pacman ('P')
    int pacmanIdx = std::rand() % vertices.size();
    int pacmanX = vertices[pacmanIdx].first;
    int pacmanY = vertices[pacmanIdx].second;
    tablero[pacmanX][pacmanY] = 'P';           // Coloca a Pacman en el tablero

    // Selecciona un fantasma aleatorio (diferente de Pacman) como objetivo y lo convierte en 'f'
    int fantasmaObjetivoIdx;
    do {
        fantasmaObjetivoIdx = std::rand() % vertices.size();
    } while (fantasmaObjetivoIdx == pacmanIdx); // Evita seleccionar la posición de Pacman

    int objetivoX = vertices[fantasmaObjetivoIdx].first;
    int objetivoY = vertices[fantasmaObjetivoIdx].second;
    tablero[objetivoX][objetivoY] = 'f';       // Marca el objetivo con 'f'

    imprimirTablero(tablero, archivo);                  // Imprime el tablero inicial

    Grafo grafo(filas, columnas);              // Crea un grafo para las dimensiones del tablero
    grafo.generarAristasCercanas();            // Genera aristas hacia los tres vértices más cercanos para cada vértice

    Dijkstra dijkstra(grafo);                  // Instancia el algoritmo de Dijkstra con el grafo creado
    auto camino = dijkstra.encontrarCaminoMasCorto(pacmanX, pacmanY, objetivoX, objetivoY); // Encuentra el camino más corto

    // Muestra a Pacman moviéndose hacia el objetivo paso a paso
    for (const auto& pos : camino) {
        int x = pos.first, y = pos.second;
        tablero[pacmanX][pacmanY] = '.';       // Limpia la posición anterior de Pacman
        pacmanX = x;
        pacmanY = y;
        tablero[pacmanX][pacmanY] = 'P';       // Coloca a Pacman en la nueva posición

        limpiarPantalla();                     // Limpia la pantalla para mostrar solo el estado actual del tablero
        std::cout << "Fantasma objetivo en: (" << objetivoX << ", " << objetivoY << ")" << std::endl;
        std::cout << "--------------------------------" << std::endl;
        archivo << "Fantasma objetivo en: (" << objetivoX << ", " << objetivoY << ")" << std::endl;
        archivo << "--------------------------------" << std::endl;

        imprimirTablero(tablero, archivo);              // Imprime el tablero actualizado
        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Pausa de 1 segundo para animar el movimiento
    }

    std::cout << "¡Pacman alcanzó al fantasma!" << std::endl; // Mensaje final cuando Pacman llega al objetivo
    archivo << "¡Pacman alcanzó al fantasma!" << std::endl; // Mensaje final en archivo
    archivo.close();  // Cierra el archivo de salida
    return 0;
}

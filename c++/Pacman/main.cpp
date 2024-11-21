#include "dijkstra.h" // Incluye el archivo de cabecera con la implementación del grafo y Dijkstra
#include "tablero.h"  // Incluye el archivo de cabecera con la implementación del tablero
#include <iostream>   // Para entrada y salida estándar
#include <vector>     // Para usar el contenedor vector
#include <cstdlib>    // Para generación de números aleatorios
#include <ctime>      // Para usar time como semilla en la aleatoriedad
#include <cmath>      // Para cálculos matemáticos, como la raíz cuadrada
#include <thread>     // Para la funcionalidad de pausa con sleep_for
#include <chrono>     // Para especificar la duración de la pausa
#include <fstream>    // Para trabajar con archivos
#include <algorithm>  // Para usar std::sort

// Función para obtener un fantasma aleatorio
int obtenerFantasmaAleatorio(const std::vector<std::pair<int, int>>& vertices, const Tablero& tablero) {
    std::vector<int> fantasmas;
    for (int i = 0; i < vertices.size(); ++i) {
        int x = vertices[i].first;
        int y = vertices[i].second;
        if (tablero.obtenerCelda(x, y) == 'F' || tablero.obtenerCelda(x, y) == 'f') {
            fantasmas.push_back(i);
        }
    }
    if (fantasmas.empty()) return -1; // No hay más fantasmas
    return fantasmas[std::rand() % fantasmas.size()];
}

int main() {
    int filas, columnas;
    std::cout << "Ingresa el número de filas: ";
    std::cin >> filas;                             // Recibe número de filas para el tablero
    std::cout << "Ingresa el número de columnas: ";
    std::cin >> columnas;

    // Abre un archivo de salida
    std::ofstream archivo("salida.txt"); // Abre un archivo de salida para escribir el estado del tablero

    // Inicializa el tablero
    Tablero tablero(filas, columnas);

    // Inicializa la semilla para generación de números aleatorios
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Genera posiciones aleatorias para colocar los vértices en el tablero
    std::vector<std::pair<int, int>> vertices;
    int numFantasmas = static_cast<int>(std::sqrt(filas * columnas));
    while (vertices.size() < numFantasmas) {
        int x = std::rand() % filas;
        int y = std::rand() % columnas;
        if (tablero.obtenerCelda(x, y) == '.') {            // Asegura que la posición está libre antes de colocar un vértice
            vertices.emplace_back(x, y);       // Agrega la posición a la lista de vértices
            tablero.colocarFantasma(x, y);     // Marca el vértice como un fantasma ('F')
        }
    }

    // Selecciona una posición aleatoria de los vértices para colocar a Pacman ('P')
    int pacmanX = std::rand() % filas;
    int pacmanY = std::rand() % columnas;
    while (tablero.obtenerCelda(pacmanX, pacmanY) != '.') {
        pacmanX = std::rand() % filas;
        pacmanY = std::rand() % columnas;
    }
    tablero.colocarPacman(pacmanX, pacmanY);   // Coloca a Pacman en el tablero

    tablero.imprimirTablero(archivo);          // Imprime el tablero inicial

    // Crea un grafo con los vértices de Pacman y los fantasmas
    Grafo grafo(vertices.size() + 1); // +1 para incluir a Pacman
    int pacmanIdx = vertices.size();  // Pacman será el último vértice en el grafo
    vertices.emplace_back(pacmanX, pacmanY); // Agrega la posición de Pacman a la lista de vértices

    // Genera aristas entre Pacman y los fantasmas, y entre los fantasmas
    for (int i = 0; i < vertices.size(); ++i) {
        std::vector<std::pair<int, int>> distancias;
        for (int j = 0; j < vertices.size(); ++j) {
            if (i != j) {
                int distancia = std::abs(vertices[i].first - vertices[j].first) + std::abs(vertices[i].second - vertices[j].second);
                distancias.emplace_back(distancia, j);
            }
        }
        std::sort(distancias.begin(), distancias.end());
        for (int k = 0; k < 3 && k < distancias.size(); ++k) {
            grafo.agregarArista(i, distancias[k].second, distancias[k].first);
        }
    }

    Dijkstra dijkstra(grafo);                  // Instancia el algoritmo de Dijkstra con el grafo creado

    // Selecciona un fantasma aleatorio como objetivo
    int destino = obtenerFantasmaAleatorio(vertices, tablero);
    if (destino == -1) {
        std::cout << "No hay fantasmas en el tablero." << std::endl;
        return 0;
    }

    int objetivoX = vertices[destino].first;
    int objetivoY = vertices[destino].second;
    tablero.establecerCelda(objetivoX, objetivoY, 'f'); // Marca el fantasma objetivo con 'f' minúscula
    std::cout << "Pacman va a ir por el fantasma en la posición: (" << objetivoX << ", " << objetivoY << ")" << std::endl;
    archivo << "Pacman va a ir por el fantasma en la posición: (" << objetivoX << ", " << objetivoY << ")" << std::endl;

    auto camino = dijkstra.encontrarCaminoMasCorto(pacmanIdx, destino); // Encuentra el camino más corto

    // Muestra a Pacman moviéndose hacia el objetivo paso a paso
    for (int i = 1; i < camino.size(); ++i) {
        int x = vertices[camino[i]].first, y = vertices[camino[i]].second;
        int prevX = vertices[camino[i - 1]].first, prevY = vertices[camino[i - 1]].second;

        // Mueve a Pacman casilla por casilla
        while (pacmanX != x || pacmanY != y) {
            if (pacmanX < x) pacmanX++;
            else if (pacmanX > x) pacmanX--;
            else if (pacmanY < y) pacmanY++;
            else if (pacmanY > y) pacmanY--;

            tablero.moverPacman(pacmanX, pacmanY);
            if (tablero.obtenerCelda(pacmanX, pacmanY) == 'F' || tablero.obtenerCelda(pacmanX, pacmanY) == 'f') {
                std::cout << "¡Pacman se comió un fantasma en: (" << pacmanX << ", " << pacmanY << ")!" << std::endl;
                archivo << "¡Pacman se comió un fantasma en: (" << pacmanX << ", " << pacmanY << ")!" << std::endl;
            }
            tablero.colocarPacman(pacmanX, pacmanY);       // Coloca a Pacman en la nueva posición

            tablero.limpiarPantalla();         // Limpia la pantalla para mostrar solo el estado actual del tablero
            std::cout << "Fantasma objetivo en: (" << objetivoX << ", " << objetivoY << ")" << std::endl;
            std::cout << "--------------------------------" << std::endl;
            archivo << "Fantasma objetivo en: (" << objetivoX << ", " << objetivoY << ")" << std::endl;
            archivo << "--------------------------------" << std::endl;

            tablero.imprimirTablero(archivo);  // Imprime el tablero actualizado
            std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Pausa de 0.5 segundos para animar el movimiento

            // Termina el programa si Pacman alcanza al fantasma objetivo
            if (pacmanX == objetivoX && pacmanY == objetivoY) {
                std::cout << "¡Pacman alcanzó al fantasma objetivo!" << std::endl;
                archivo << "¡Pacman alcanzó al fantasma objetivo!" << std::endl;
                archivo.close();  // Cierra el archivo de salida
                return 0;
            }
        }
    }

    archivo.close();  // Cierra el archivo de salida
    std::cout << "¡Pacman se ha comido a todos los fantasmas!" << std::endl;
    return 0;
}
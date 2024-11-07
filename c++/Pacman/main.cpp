#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <thread>  // Para std::this_thread::sleep_for
#include <chrono>  // Para std::chrono::milliseconds
#include "dijkstra.h"

void imprimirTablero(const std::vector<std::vector<char>>& tablero) {
    for (const auto& fila : tablero) {
        for (char celda : fila) {
            std::cout << celda << ' ';
        }
        std::cout << std::endl;
    }
}

void limpiarPantalla() {
    // Imprime 50 líneas en blanco para simular una pantalla limpia
    for (int i = 0; i < 50; ++i) std::cout << std::endl;
}

int main() {
    int filas, columnas;
    std::cout << "Ingresa el número de filas (filas): ";
    std::cin >> filas;
    std::cout << "Ingresa el número de columnas (columnas): ";
    std::cin >> columnas;

    std::vector<std::vector<char>> tablero(filas, std::vector<char>(columnas, '.'));

    int numVertices = static_cast<int>(std::sqrt(filas * columnas));
    if (numVertices < 1) numVertices = 1;

    std::srand(static_cast<unsigned int>(std::time(0)));

    int pacmanX = std::rand() % filas;
    int pacmanY = std::rand() % columnas;
    tablero[pacmanX][pacmanY] = 'P';

    std::vector<std::pair<int, int>> fantasmas;
    for (int i = 1; i < numVertices; ++i) {
        int fantasmaX, fantasmaY;
        do {
            fantasmaX = std::rand() % filas;
            fantasmaY = std::rand() % columnas;
        } while (tablero[fantasmaX][fantasmaY] != '.');

        tablero[fantasmaX][fantasmaY] = 'F';
        fantasmas.emplace_back(fantasmaX, fantasmaY);
    }

    Grafo grafo(filas, columnas);
    for (int x = 0; x < filas; ++x) {
        for (int y = 0; y < columnas; ++y) {
            if (x > 0) grafo.agregarArista(x, y, x - 1, y, 1);  // Arriba
            if (x < filas - 1) grafo.agregarArista(x, y, x + 1, y, 1); // Abajo
            if (y > 0) grafo.agregarArista(x, y, x, y - 1, 1);  // Izquierda
            if (y < columnas - 1) grafo.agregarArista(x, y, x, y + 1, 1); // Derecha
        }
    }

    int indiceFantasmaObjetivo = std::rand() % fantasmas.size();
    int objetivoX = fantasmas[indiceFantasmaObjetivo].first;
    int objetivoY = fantasmas[indiceFantasmaObjetivo].second;

    std::cout << "Fantasma objetivo en: (" << objetivoX << ", " << objetivoY << ")" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    tablero[objetivoX][objetivoY] = 'f';
    imprimirTablero(tablero);

    Dijkstra dijkstra(grafo);
    auto camino = dijkstra.encontrarCaminoMasCorto(pacmanX, pacmanY, objetivoX, objetivoY);

    // Mueve "P" paso a paso en el tablero
    for (size_t i = 0; i < camino.size(); ++i) {
        int x = camino[i].first;
        int y = camino[i].second;

        // Limpia la posición anterior
        tablero[pacmanX][pacmanY] = '.';
        pacmanX = x;
        pacmanY = y;
        tablero[pacmanX][pacmanY] = 'P';

        // Limpia la pantalla y pausa medio segundo (pantalla negra)
        limpiarPantalla();  // Simula pantalla limpia
        std::this_thread::sleep_for(std::chrono::milliseconds(500));  // Pausa para la pantalla en negro

        // Imprime el tablero actualizado
        std::cout << "Fantasma objetivo en: (" << objetivoX << ", " << objetivoY << ")" << std::endl;
        std::cout << "--------------------------------" << std::endl;
        imprimirTablero(tablero);
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));  // Pausa para ver el movimiento un segundo
    }

    std::cout << "¡Pacman alcanzó al fantasma!" << std::endl;

    return 0;
}

#include "tablero.h"

// Constructor que inicializa el tablero con el número de filas y columnas especificado
Tablero::Tablero(int filas, int columnas) : filas(filas), columnas(columnas), tablero(filas, std::vector<char>(columnas, '.')) {}

// Coloca a Pacman en la posición (x, y) del tablero
void Tablero::colocarPacman(int x, int y) {
    tablero[x][y] = 'P';
}

// Coloca un fantasma en la posición (x, y) del tablero
void Tablero::colocarFantasma(int x, int y) {
    tablero[x][y] = 'F';
}

// Mueve a Pacman a la posición (x, y) del tablero
void Tablero::moverPacman(int x, int y) {
    // Limpia la posición anterior de Pacman
    for (auto& fila : tablero) {
        for (auto& celda : fila) {
            if (celda == 'P') {
                celda = '.';
            }
        }
    }
    // Coloca a Pacman en la nueva posición
    tablero[x][y] = 'P';
}

// Imprime el estado actual del tablero en la consola y en un archivo
void Tablero::imprimirTablero(std::ofstream& archivo) const {
    for (const auto& fila : tablero) {
        for (char celda : fila) {
            std::cout << celda << ' ';
            archivo << celda << ' ';
        }
        std::cout << std::endl;
        archivo << std::endl;
    }
    archivo << "--------------------------------" << std::endl;
    std::cout << "--------------------------------" << std::endl;
}

// Limpia la pantalla para una mejor visualización del movimiento
void Tablero::limpiarPantalla() const {
    for (int i = 0; i < 50; ++i) std::cout << std::endl;
}

// Obtiene el valor de la celda en la posición (x, y) del tablero
char Tablero::obtenerCelda(int x, int y) const {
    return tablero[x][y];
}

// Establece el valor de la celda en la posición (x, y) del tablero
void Tablero::establecerCelda(int x, int y, char valor) {
    tablero[x][y] = valor;
}
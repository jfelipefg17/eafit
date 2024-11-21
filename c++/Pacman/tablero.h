#ifndef TABLERO_H
#define TABLERO_H

#include <vector>
#include <utility>
#include <iostream>
#include <fstream>

// Clase Tablero para manejar la representación y animación del tablero
class Tablero {
public:
    // Constructor que inicializa el tablero con el número de filas y columnas especificado
    Tablero(int filas, int columnas);

    // Coloca a Pacman en la posición (x, y) del tablero
    void colocarPacman(int x, int y);

    // Coloca un fantasma en la posición (x, y) del tablero
    void colocarFantasma(int x, int y);

    // Mueve a Pacman a la posición (x, y) del tablero
    void moverPacman(int x, int y);

    // Imprime el estado actual del tablero en la consola y en un archivo
    void imprimirTablero(std::ofstream& archivo) const;

    // Limpia la pantalla para una mejor visualización del movimiento
    void limpiarPantalla() const;

    // Obtiene el valor de la celda en la posición (x, y) del tablero
    char obtenerCelda(int x, int y) const;

    // Establece el valor de la celda en la posición (x, y) del tablero
    void establecerCelda(int x, int y, char valor);

private:
    int filas, columnas; // Número de filas y columnas del tablero
    std::vector<std::vector<char>> tablero; // Matriz que representa el tablero
};

#endif
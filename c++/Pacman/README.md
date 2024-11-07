# Proyecto de Dijkstra: Pacman y Fantasmas

Este programa implementa una simulación donde Pacman, representado por la letra "P", se mueve a través de un tablero en busca de un fantasma, representado por la letra "f". Utiliza el algoritmo de Dijkstra para encontrar el camino más corto entre Pacman y el fantasma, evitando obstáculos (no representados en este caso). El movimiento de Pacman en el tablero se muestra paso a paso.

## Descripción

El programa crea un tablero de tamaño especificado por el usuario, coloca a Pacman en una posición aleatoria, y coloca varios fantasmas en posiciones aleatorias. Luego, Pacman utiliza el algoritmo de Dijkstra para encontrar el camino más corto hacia uno de los fantasmas, y el programa muestra el movimiento de Pacman hasta que alcanza al fantasma.

## Datos básicos del programa

El programa utiliza las siguientes entradas:
- **Filas (filas)**: El número de filas del tablero.
- **Columnas (columnas)**: El número de columnas del tablero.

El número de fantasmas se genera aleatoriamente en base al tamaño del tablero.

## ¿Cómo funciona?

1. **Generación del Tablero**: 
   El tablero es una matriz de caracteres con el tamaño especificado por el usuario. Las celdas vacías se representan con un punto (`.`), Pacman con una "P" y los fantasmas con una "F". Un fantasma objetivo es seleccionado aleatoriamente.

2. **Algoritmo de Dijkstra**: 
   El programa usa el algoritmo de Dijkstra para encontrar el camino más corto desde la posición de Pacman hasta la posición de un fantasma. El grafo está representado por un conjunto de aristas entre las celdas adyacentes (arriba, abajo, izquierda, derecha).

3. **Movimiento de Pacman**: 
   Una vez que Dijkstra determina el camino más corto, Pacman comienza a moverse paso a paso desde su posición inicial hasta la posición del fantasma. El tablero se imprime después de cada movimiento, y se simula una breve pausa para observar el movimiento.

4. **Finalización**: 
   El proceso termina cuando Pacman alcanza al fantasma, y el programa imprime un mensaje indicando que Pacman ha alcanzado al fantasma.

## Pasos para correr el programa

### 1. Compilar el código

Para compilar el programa, abre la terminal y usa el siguiente comando:

```bash
g++ -std=c++11 main.cpp dijkstra.cpp -o programa

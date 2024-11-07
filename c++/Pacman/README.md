# Proyecto de Dijkstra: Pacman

Este programa implementa una simulación en la que Pacman, representado por la letra "P", se desplaza a través de un tablero en busca de un fantasma objetivo, representado por la letra "f". Utiliza el algoritmo de Dijkstra para encontrar el camino más corto entre Pacman y el fantasma objetivo. El movimiento de Pacman se muestra paso a paso en el tablero.

## Descripción

El programa crea un tablero de tamaño especificado por el usuario, coloca a Pacman en una posición aleatoria, y coloca varios fantasmas en posiciones aleatorias. Luego, Pacman utiliza el algoritmo de Dijkstra para encontrar el camino más corto hacia uno de los fantasmas, y el programa muestra el movimiento de Pacman hasta que alcanza al fantasma.

## Datos básicos del programa

El programa utiliza las siguientes entradas:
- **Filas (filas)**: El número de filas del tablero.
- **Columnas (columnas)**: El número de columnas del tablero.

### Uso de la matriz:
El tablero se representa como una matriz de caracteres, donde cada celda contiene un valor que puede ser uno de los siguientes:
- **'.'**: Celda vacía.
- **'P'**: Pacman (el personaje principal).
- **'F'**: Fantasma (un objetivo a alcanzar por Pacman).
- **'f'**: Fantasma objetivo (el objetivo final que Pacman debe alcanzar).

El tamaño del tablero es definido por el usuario al inicio del programa, y la matriz se llena con puntos ('.') por defecto. Posteriormente, se colocan aleatoriamente los fantasmas y Pacman en celdas vacías.

### Uso de grafos:
El tablero es representado como un **grafo** en el cual cada celda del tablero actúa como un **nodo**. Las conexiones entre las celdas adyacentes (arriba, abajo, izquierda, derecha) se representan como **aristas**. De esta manera, el programa utiliza un grafo de nodos conectados para modelar el tablero de Pacman, donde cada celda tiene aristas hacia las celdas vecinas.

### Uso del algoritmo de Dijkstra:
El programa emplea el **algoritmo de Dijkstra** para encontrar el camino más corto desde la posición inicial de Pacman hasta la posición del fantasma objetivo. Este algoritmo funciona buscando la ruta más corta en un grafo, minimizando la "distancia" total recorrida.

Las distancias entre las celdas adyacentes son consideradas uniformes (todas son 1), lo que simplifica el uso de Dijkstra al ser un algoritmo eficiente para grafos ponderados.

### Uso de la distancia de Manhattan:
El cálculo de la distancia entre las celdas adyacentes se basa en la **distancia de Manhattan**. Esto significa que la distancia entre dos celdas se calcula sumando las diferencias absolutas de sus coordenadas (es decir, la suma de la diferencia en filas y columnas). Por ejemplo, la distancia entre la celda (2, 3) y (4, 5) sería |2-4| + |3-5| = 4.

La distancia de Manhattan es útil aquí porque Pacman solo puede moverse a las celdas adyacentes en las direcciones cardinales (arriba, abajo, izquierda, derecha), lo cual coincide con este tipo de cálculo.

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

```bash
./programa
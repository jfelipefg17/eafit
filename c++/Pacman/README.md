# Proyecto final Pacman

## Descripción
Este proyecto implementa un juego tipo **Pacman** en el que Pacman se mueve por un tablero para alcanzar y comer fantasmas. El objetivo es que Pacman siga el camino más corto hacia un fantasma objetivo, comiendo cualquier otro fantasma que encuentre en su camino. 

El juego utiliza:
- Una estructura de datos de **grafo** para representar las conexiones entre Pacman y los fantasmas.
- El algoritmo de **Dijkstra** para encontrar el camino más corto.

---

## Estructura de Datos Utilizada

### Grafo
El grafo representa las conexiones entre Pacman y los fantasmas. 
- **Vértices**: Representan las posiciones en el tablero ocupadas por Pacman o un fantasma.  
- **Aristas**: Representan las conexiones entre vértices, donde el peso es la distancia Manhattan entre los vértices conectados.

### Tablero
El tablero es una matriz bidimensional que muestra el estado del juego.  
- `.`: Celda vacía.  
- `P`: Pacman.  
- `F`: Fantasma.  
- `f`: Fantasma objetivo.  

---

## Algoritmo Implementado

### Algoritmo de Dijkstra
Se utiliza el algoritmo de Dijkstra para encontrar el camino más corto desde Pacman hasta el fantasma objetivo en el grafo. El proceso es el siguiente:

1. Inicializa las distancias de todos los vértices a infinito, excepto la distancia del vértice inicial (Pacman), que se establece en 0.
2. Usa una cola de prioridad para procesar los vértices en orden de distancia mínima.
3. Para cada vértice procesado, actualiza las distancias de sus vecinos si se encuentra un camino más corto.
4. Continúa hasta procesar todos los vértices o alcanzar el vértice objetivo.

---

## Estrategia Seguida para Resolver el Problema

1. **Inicialización del Tablero**: 
   - Se crea un tablero bidimensional y se colocan Pacman y los fantasmas en posiciones aleatorias.

2. **Creación del Grafo**: 
   - Se genera un grafo con vértices para Pacman y los fantasmas.
   - Se añaden aristas entre cada vértice y los tres vértices más cercanos (según la distancia Manhattan).

3. **Algoritmo de Dijkstra**: 
   - Encuentra el camino más corto desde Pacman hasta el fantasma objetivo.

4. **Movimiento de Pacman**: 
   - Pacman se mueve casilla por casilla siguiendo el camino más corto calculado.
   - La animación del movimiento se muestra en la consola.

5. **Finalización del Juego**: 
   - El juego termina cuando Pacman alcanza y se come al fantasma objetivo.

---

## Instrucciones para Compilar y Ejecutar

### Compilar el Programa
Asegúrate de tener `g++` instalado en tu sistema. Navega al directorio donde están los archivos fuente y ejecuta el siguiente comando en la terminal:

```bash
g++ -std=c++11 main.cpp dijkstra.cpp tablero.cpp -o programa

./programa

# Grafo y Algoritmo de Dijkstra

Este programa implementa un grafo dirigido en C++ y utiliza el algoritmo de Dijkstra para calcular el camino más corto entre dos nodos en función de la distancia y la dificultad de los arcos. El usuario puede ingresar nodos de origen y destino representados por letras de la A a la P, y el programa mostrará el camino mínimo junto con el costo total.

## Estructuras de Datos Utilizadas

1. **Arc**: 
   - Representa un arco en el grafo, con los siguientes atributos:
     - `destino`: el nodo destino del arco.
     - `distancia`: la distancia del arco.
     - `dificultad`: un factor que afecta el costo total del camino.

2. **Graph**: 
   - Representa el grafo, que contiene:
     - `numNodos`: el número total de nodos en el grafo.
     - `adyacencia`: un vector de vectores que almacena todos los arcos salientes de cada nodo.

3. **Dijkstra**:
   - Se implementa el algoritmo de Dijkstra para encontrar el camino más corto desde un nodo de origen a un nodo de destino.

## Pasos para Correr el Programa

1. **Compilar el Código**:
   - Asegúrate de que todos los archivos necesarios (`grafo.h`, `grafo.cpp`, `dijkstra.h`, `dijkstra.cpp`, y `main.cpp`) estén en el mismo directorio.
   - Abre una terminal y navega al directorio donde se encuentran los archivos.

2. **Usar el Comando de Compilación**:
   ```bash
   g++ -o grafo_programa main.cpp grafo.cpp dijkstra.cpp

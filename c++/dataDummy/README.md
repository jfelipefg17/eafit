# Proyecto de Gimnastas

Este proyecto en C++ genera un conjunto de objetos `Person` que representan gimnastas, con datos aleatorios como nombre, edad, país, dificultad y ejecución. Luego, los ordena según su puntaje total (la suma de la dificultad y la ejecución) usando el algoritmo de ordenación Merge Sort. Al final, se muestran los 10 mejores y los 5 peores gimnastas.

 Archivos-**main.cpp**: Contiene la lógica principal del programa, incluyendo la generación de datos aleatorios y la ordenación de los gimnastas.

-**Person.h / Person.cpp**: Define la clase `Person` con atributos y métodos para manejar los datos de los gimnastas.

-**Node.h / Node.cpp**: Define la clase `Node`, que almacena un objeto `Person`.

-**File.h / File.cpp**: Define la clase `File` para leer nombres y países desde archivos y generar datos aleatorios.

## Compilación y Ejecución

Para compilar el programa, sigue estos pasos:

1. Compila el archivo `file.cpp`:
    ```bash
    g++ -c file.cpp
    ```
2. Compila el archivo `ticket.cpp`:
    ```bash
    g++ -c ticket.cpp
    ```

3. Compila el archivo `bts.cpp`:
    ```bash
    g++ -c bst.cpp
    ```

4. Compila y enlaza el archivo `main.cpp` con los objetos generados:
    ```bash
    g++ -std=c++11 -o main main.cpp ticket.o file.o bst.o

    ```
5. Ejecuta el programa:
    ```bash
    ./main
    ```


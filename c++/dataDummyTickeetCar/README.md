# Proyecto de Gimnastas

## Descripción

Este proyecto simula un sistema de control y consulta de infracciones de velocidad cometidas por vehículos. Los datos de los vehículos y las infracciones se almacenan de forma estructurada y permiten consultas eficientes sobre las infracciones de un vehículo específico en un rango de fechas.

## Estructuras de Datos Utilizadas

El sistema utiliza las siguientes estructuras de datos:

1. **Clase `Car`**:
   - Almacena información sobre los vehículos, incluyendo la placa y el ID del propietario.
   - Contiene una lista de `tickets` asociados, que representan las infracciones cometidas por el vehículo.

2. **Clase `Ticket`**:
   - Guarda detalles de las infracciones, como la fecha y la gravedad (si el vehículo excedió el límite de velocidad).
   - Cada infracción está vinculada a un coche específico.

3. **`std::vector`**:
   - Se utiliza tanto para almacenar coches como infracciones. Los `std::vector` son estructuras de datos dinámicas que permiten acceder y almacenar los elementos de manera eficiente.
   - Al ser una estructura de acceso secuencial, facilita la organización y la búsqueda de información cuando el tamaño de los datos no es muy grande.

## Estrategia de Consulta

- **Búsqueda por Placa**: Se realiza una búsqueda lineal sobre el vector de coches para encontrar el vehículo cuya placa coincide con la ingresada por el usuario. Aunque esta operación tiene complejidad O(n), es adecuada para conjuntos de datos de tamaño moderado.

- **Consulta de Tickets por Fecha**: Después de encontrar el coche correcto, el programa filtra los tickets de acuerdo con el rango de fechas solicitado por el usuario. Esto permite obtener todas las infracciones de un coche en un periodo de tiempo determinado.

## Motivo de la Elección

La decisión de usar `std::vector` como la estructura base de almacenamiento se justifica por su simplicidad y eficiencia en este caso, ya que el número de registros no es grande. Aunque una búsqueda lineal no es la más eficiente para conjuntos de datos muy grandes, es suficiente para este proyecto. Si el volumen de datos creciera considerablemente, se podrían considerar estructuras como `std::unordered_map` para mejorar el rendimiento en búsquedas.

## Instrucciones de Compilación y Ejecución

Para compilar y ejecutar el programa, sigue los siguientes pasos:

1. Compila el archivo `file.cpp`:
    ```bash
    g++ -c file.cpp
    ```

2. Compila el archivo `ticket.cpp`:
    ```bash
    g++ -c ticket.cpp
    ```

3. Compila el archivo `car.cpp`:
    ```bash
    g++ -c car.cpp
    ```

4. Compila y enlaza el archivo `main.cpp` junto con los objetos generados:
    ```bash
    g++ -std=c++11 -o main main.cpp file.o ticket.o car.o
    ```

5. Ejecuta el programa:
    ```bash
    ./main
    ```

Este documento proporciona las instrucciones de compilación y ejecución, así como la explicación de las estructuras de datos y la estrategia de consulta implementada en el proyecto.

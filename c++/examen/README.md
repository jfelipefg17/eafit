# Proyecto de FotoMultas

## Descripción

Este proyecto simula un sistema de control y consulta de infracciones de velocidad cometidas por vehículos. Los datos de los vehículos y las infracciones se almacenan de forma estructurada y permiten consultas eficientes sobre las infracciones de un vehículo específico en un rango de fechas.

## Estructuras de Datos Utilizadas

El sistema utiliza las siguientes estructuras de datos:

1. **Clase `Car`**:
   - Almacena información sobre los vehículos, incluyendo la placa, nombre propetario y el ID del propietario.

2. **Clase `Ticket`**:
   - Guarda detalles de las infracciones, Id camara, IdImagen, fecha, si exedio o no la velociad y el carro (incluyendo la placa, nombre propetario y el ID del propietario)
   - Cada infracción está vinculada a un coche específico.

3. **`std::vector`**:
   - Se utiliza tanto para almacenar coches como infracciones.
   - Al ser una estructura de acceso secuencial, facilita la organización y la búsqueda de información.

## Estrategia de Consulta

- **Búsqueda por Placa**: Se realiza una búsqueda lineal sobre el vector de coches para encontrar el vehículo cuya placa coincide con la ingresada por el usuario.

- **Consulta de Tickets por Fecha**: Después de encontrar el coche correcto, el programa filtra los tickets de acuerdo con el rango de fechas solicitado por el usuario.

## Motivo de la Elección

Como son datos ordenados y del mismo tipo guardar los datos en un arreglo permite una busqueda facil.

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

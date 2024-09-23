#ifndef CAR_H
#define CAR_H
// Guarda de inclusión para evitar que este archivo se incluya más de una vez.

#include <iostream>
// Incluye la biblioteca para la entrada y salida estándar.
#include <string>
// Incluye la biblioteca para manejar cadenas de caracteres.

class Car {
    // Declaración de la clase Car.

private:
    std::string name;   // Nombre del propietario.
    long long idOwner;  // ID del propietario.
    std::string plate;  // Placa del vehículo.

public:
    // Constructor por defecto.
    Car();

    // Constructor parametrizado que inicializa el coche con el ID, placa y nombre del propietario.
    Car(long long idOwner, const std::string &plate, const std::string &name);

    // Métodos getter para acceder a los atributos privados.
    std::string getName() const;          // Retorna el nombre del propietario.
    long long getIdOwner() const;         // Retorna el ID del propietario.
    std::string getPlate() const;         // Retorna la placa del vehículo.

    // Métodos setter para modificar los atributos privados.
    void setIdOwner(long long idOwner);   // Establece el ID del propietario.
    void setPlate(const std::string &plate); // Establece la placa del vehículo.
    void setName(const std::string &name); // Establece el nombre del propietario.

    // Método que devuelve todos los datos del coche como una cadena de texto.
    std::string getData() const;

    // Sobrecarga del operador de inserción << para imprimir objetos Car.
    friend std::ostream& operator<<(std::ostream &out, const Car &car);

    // Sobrecarga de los operadores de comparación.
    bool operator>(const Car &other) const; // Compara si este coche es "mayor" que otro.
    bool operator<(const Car &other) const;  // Compara si este coche es "menor" que otro.
    bool operator==(const Car &other) const; // Compara si este coche es igual a otro.

};

#endif // CAR_H
// Fin de la guarda de inclusión.

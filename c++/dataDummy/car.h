#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

class Car {
private:
    std::string name;   // Nombre del propietario
    long long idOwner;  // ID del propietario
    std::string plate;  // Placa del vehículo

public:
    // Constructor por defecto
    Car();

    // Constructor parametrizado
    Car(long long idOwner, const std::string &plate, const std::string &name);

    // Métodos getter
    std::string getName() const;
    long long getIdOwner() const;
    std::string getPlate() const;

    // Métodos setter
    void setIdOwner(long long idOwner);
    void setPlate(const std::string &plate);
    void setName(const std::string &name);

    // Método para obtener todos los datos como cadena de texto
    std::string getData() const;

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream &out, const Car &car);

    // Sobrecarga de los operadores >, < y ==
    bool operator>(const Car &other) const;
    bool operator<(const Car &other) const;
    bool operator==(const Car &other) const;
};

#endif // CAR_H

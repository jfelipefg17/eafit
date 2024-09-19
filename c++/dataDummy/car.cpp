#include "car.h"
#include <sstream>

// Constructor por defecto
Car::Car() : name(""), idOwner(0), plate("") {}

// Constructor parametrizado
Car::Car(long long idOwner, const std::string &plate, const std::string &name)
    : name(name), idOwner(idOwner), plate(plate) {}

// Métodos getter
std::string Car::getName() const { return name; }
long long Car::getIdOwner() const { return idOwner; }
std::string Car::getPlate() const { return plate; }

// Métodos setter
void Car::setIdOwner(long long idOwner) { this->idOwner = idOwner; }
void Car::setPlate(const std::string &plate) { this->plate = plate; }
void Car::setName(const std::string &name) { this->name = name; }

// Método para obtener todos los datos como cadena de texto
std::string Car::getData() const {
    std::ostringstream oss;
    oss << "Name: " << name << ", ID Owner: " << idOwner << ", Plate: " << plate;
    return oss.str();
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream &out, const Car &car) {
    out << car.getData();
    return out;
}

// Sobrecarga de los operadores de comparación
bool Car::operator>(const Car &other) const { return this->idOwner > other.idOwner; }
bool Car::operator<(const Car &other) const { return this->idOwner < other.idOwner; }
bool Car::operator==(const Car &other) const { return this->idOwner == other.idOwner; }

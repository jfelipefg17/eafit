#include "car.h"
#include <sstream>

// Incluimos el archivo de cabecera `car.h` que contiene las declaraciones de la clase Car.
// También incluimos la librería `sstream` para utilizar `std::ostringstream`
// que permite construir cadenas de texto dinámicamente.

// Constructor por defecto
Car::Car() : name(""), idOwner(0), plate("") {}
// El constructor por defecto inicializa los miembros de datos a valores predeterminados:
// `name` a una cadena vacía, `idOwner` a 0, y `plate` a una cadena vacía.

// Constructor parametrizado
Car::Car(long long idOwner, const std::string &plate, const std::string &name)
    : name(name), idOwner(idOwner), plate(plate) {}
// Este constructor parametrizado inicializa los atributos de la clase con los valores
// proporcionados. `name` se inicializa con el parámetro `name`,
// `idOwner` con `idOwner`, y `plate` con `plate`.

// Métodos getter
std::string Car::getName() const { return name; }
// Devuelve el valor del atributo `name` (nombre del coche).
long long Car::getIdOwner() const { return idOwner; }
// Devuelve el valor del atributo `idOwner` (ID del propietario).
std::string Car::getPlate() const { return plate; }
// Devuelve el valor del atributo `plate` (número de matrícula del coche).

// Métodos setter
void Car::setIdOwner(long long idOwner) { this->idOwner = idOwner; }
// Asigna el valor de `idOwner` al atributo `idOwner` del objeto.
// El uso de `this->` indica que estamos accediendo al atributo de la clase.
void Car::setPlate(const std::string &plate) { this->plate = plate; }
// Asigna el valor de `plate` al atributo `plate`.
void Car::setName(const std::string &name) { this->name = name; }
// Asigna el valor de `name` al atributo `name`.

// Método para obtener todos los datos como cadena de texto
std::string Car::getData() const {
    std::ostringstream oss;
    oss << "Name: " << name << ", ID Owner: " << idOwner << ", Plate: " << plate;
    return oss.str();
}
// `getData` devuelve una cadena de texto que contiene la información completa del coche.
// Utiliza `std::ostringstream` para construir la cadena que incluye `name`, `idOwner` y `plate`.
// `oss.str()` convierte el contenido del string stream en una cadena de texto.

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream &out, const Car &car) {
    out << car.getData();
    return out;
}
// Sobrecarga del operador de inserción `<<` para la clase `Car`. Permite que un objeto `Car`
// se pueda imprimir directamente utilizando `std::cout`. Llama al método `getData` del objeto `Car`
// para obtener la representación en forma de cadena y la inserta en el flujo de salida `out`.

// Sobrecarga de los operadores de comparación
bool Car::operator>(const Car &other) const { return this->idOwner > other.idOwner; }
// Sobrecarga del operador `>` para comparar dos objetos `Car`. Devuelve `true` si el `idOwner`
// del objeto actual es mayor que el del otro objeto `Car`, de lo contrario, devuelve `false`.

bool Car::operator<(const Car &other) const { return this->idOwner < other.idOwner; }
// Sobrecarga del operador `<`. Devuelve `true` si el `idOwner` del objeto actual es menor que
// el del otro objeto `Car`.

bool Car::operator==(const Car &other) const { return this->idOwner == other.idOwner; }
// Sobrecarga del operador `==`. Devuelve `true` si los `idOwner` de ambos objetos `Car` son iguales,
// de lo contrario, devuelve `false`.

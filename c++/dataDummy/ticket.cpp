#include "ticket.h"         // Incluye el archivo de encabezado que define la clase Ticket.
#include <sstream>          // Incluye la biblioteca <sstream> para usar std::ostringstream.


// Constructor por defecto
Ticket::Ticket()
    : name(""), year(0), month(0), day(0), idPicture(0), idCamara(0), idOwner(0), plate(""), speedViolation(false) {}
    // Inicializa todos los miembros con valores predeterminados: cadena vacía para los strings,
    // cero para los enteros y falso para el booleano.


// Definición del constructor parametrizado
Ticket::Ticket(int year, int month, int day, int idPicture, int idCamara, long long idOwner,
               const std::string &plate, const std::string &name, bool speedViolation)
    : year(year), month(month), day(day), idPicture(idPicture), idCamara(idCamara),
      idOwner(idOwner), plate(plate), name(name), speedViolation(speedViolation) {}
    // Inicializa todos los miembros con los valores proporcionados por los parámetros del constructor.

// Definición de los métodos getter

int Ticket::getYear() const {
    return year;
    // Devuelve el año del ticket.
}

int Ticket::getMonth() const {
    return month;
    // Devuelve el mes del ticket.
}

int Ticket::getDay() const {
    return day;
    // Devuelve el día del ticket.
}

int Ticket::getIdPicture() const {
    return idPicture;
    // Devuelve el ID de la imagen del ticket.
}

int Ticket::getIdCamara() const {
    return idCamara;
    // Devuelve el ID de la cámara del ticket.
}

long long Ticket::getIdOwner() const {
    return idOwner;
    // Devuelve el ID del propietario del ticket.
}

std::string Ticket::getPlate() const {
    return plate;
    // Devuelve la placa del vehículo del ticket.
}

std::string Ticket::getName() const {
    return name;
    // Devuelve el nombre asociado al ticket.
}

bool Ticket::getSpeedViolation() const {
    return speedViolation;
    // Devuelve si el ticket es por violación de velocidad.
}

// Definición de los métodos setter

void Ticket::setYear(int year) {
    this->year = year;
    // Establece el año del ticket.
}

void Ticket::setMonth(int month) {
    this->month = month;
    // Establece el mes del ticket.
}

void Ticket::setDay(int day) {
    this->day = day;
    // Establece el día del ticket.
}

void Ticket::setIdPicture(int idPicture) {
    this->idPicture = idPicture;
    // Establece el ID de la imagen del ticket.
}

void Ticket::setIdCamara(int idCamara) {
    this->idCamara = idCamara;
    // Establece el ID de la cámara del ticket.
}

void Ticket::setIdOwner(long long idOwner) {
    this->idOwner = idOwner;
    // Establece el ID del propietario del ticket.
}

void Ticket::setPlate(const std::string &plate) {
    this->plate = plate;
    // Establece la placa del vehículo del ticket.
}

void Ticket::setName(const std::string &name) {
    this->name = name;
    // Establece el nombre asociado al ticket.
}

void Ticket::setSpeedViolation(bool violation) {
    this->speedViolation = violation;
    // Establece si el ticket es por violación de velocidad.
}

// Definición del método para obtener todos los datos como una cadena de texto
std::string Ticket::getData() const {
    std::ostringstream oss;
    // Crea un objeto std::ostringstream para construir una cadena de texto.

    oss << "Name: " << name << ", date: " << year << "-" << month << "-" << day
        << ", ID Picture: " << idPicture << ", ID Camara: " << idCamara
        << ", ID Owner: " << idOwner << ", Plate: " << plate
        << ", Speed Violation: " << (speedViolation ? "Yes" : "No");
    // Agrega los datos del ticket al flujo de salida en formato de texto.

    return oss.str();
    // Devuelve la cadena de texto construida.
}

// Definición de la sobrecarga del operador <<
std::ostream& operator<<(std::ostream &out, const Ticket &ticket) {
    out << ticket.getData();
    // Imprime los datos del ticket en el flujo de salida.
    return out;
    // Devuelve el flujo de salida.
}

// Sobrecarga de los operadores de comparación basados en la edad (year)

bool Ticket::operator>(const Ticket &other) const {
    return this->year > other.year;
    // Compara si el año del ticket actual es mayor que el del otro ticket.
}

bool Ticket::operator<(const Ticket &other) const {
    return this->year < other.year;
    // Compara si el año del ticket actual es menor que el del otro ticket.
}

bool Ticket::operator==(const Ticket &other) const {
    return this->year == other.year;
    // Compara si el año del ticket actual es igual al del otro ticket.
}

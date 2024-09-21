#include "ticket.h"
#include <sstream>

// Constructor por defecto
Ticket::Ticket()
    : year(0), month(0), day(0), idPicture(0), idCamara(0), car(), speedViolation(false) {}

// Constructor
Ticket::Ticket(int year, int month, int day, int idPicture, int idCamara, const Car &car, bool speedViolation)
    : year(year), month(month), day(day), idPicture(idPicture), idCamara(idCamara), car(car), speedViolation(speedViolation) {}


// Métodos getter
int Ticket::getYear() const { return year; }
int Ticket::getMonth() const { return month; }
int Ticket::getDay() const { return day; }
int Ticket::getIdPicture() const { return idPicture; }
int Ticket::getIdCamara() const { return idCamara; }
bool Ticket::getSpeedViolation() const { return speedViolation; }
Car Ticket::getCar() const { return car; }  // Retorna el objeto Car asociado

// Métodos setter
void Ticket::setYear(int year) { this->year = year; }
void Ticket::setMonth(int month) { this->month = month; }
void Ticket::setDay(int day) { this->day = day; }
void Ticket::setIdPicture(int idPicture) { this->idPicture = idPicture; }
void Ticket::setIdCamara(int idCamara) { this->idCamara = idCamara; }
void Ticket::setSpeedViolation(bool violation) { this->speedViolation = violation; }
void Ticket::setCar(const Car &car) { this->car = car; }  // Establece el objeto Car

// Método para obtener los datos del ticket como una cadena
std::string Ticket::getData() const {
    std::ostringstream oss;
    oss << "Date: " << year << "-" << month << "-" << day
        << ", ID Picture: " << idPicture << ", ID Camara: " << idCamara
        << ", Speed Violation: " << (speedViolation ? "Yes" : "No")
        << ", Car: [" << car.getData() << "]";
    return oss.str();
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream &out, const Ticket &ticket) {
    out << ticket.getData();
    return out;
}

// Sobrecarga de los operadores de comparación
bool Ticket::operator>(const Ticket &other) const { return this->year > other.year; }
bool Ticket::operator<(const Ticket &other) const { return this->year < other.year; }
bool Ticket::operator==(const Ticket &other) const { return this->year == other.year; }

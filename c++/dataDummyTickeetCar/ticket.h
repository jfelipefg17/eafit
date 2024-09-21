#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include <string>
#include "car.h"  // Incluye la definición de Car

class Ticket {
private:
    int year;
    int month;
    int day;
    int idPicture;
    int idCamara;
    Car car;  // Ahora Ticket tiene un atributo Car
    bool speedViolation;

public:

    // Constructor por defecto
    Ticket();
    // Constructor
    Ticket(int year, int month, int day, int idPicture, int idCamara, const Car &car, bool speedViolation = false);

    // Métodos getter y setter
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    int getIdPicture() const;
    int getIdCamara() const;
    Car getCar() const;  // Getter para Car
    bool getSpeedViolation() const;

    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);
    void setIdPicture(int idPicture);
    void setIdCamara(int idCamara);
    void setCar(const Car &car);  // Setter para Car
    void setSpeedViolation(bool violation);

    std::string getData() const;
    friend std::ostream& operator<<(std::ostream &out, const Ticket &ticket);
    bool operator>(const Ticket &other) const;
    bool operator<(const Ticket &other) const;
    bool operator==(const Ticket &other) const;
};

#endif // TICKET_H

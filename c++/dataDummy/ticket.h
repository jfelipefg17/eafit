#ifndef TICKET_H
#define TICKET_H

#include <iostream>  // Incluye la biblioteca estándar <iostream> para operaciones de entrada y salida.
#include <string>    // Incluye la biblioteca estándar <string> para usar la clase std::string.

class Ticket {
private:
    std::string name;          // Nombre del titular del ticket.
    int year;                  // Año en el que se emitió el ticket.
    int month;                 // Mes en el que se emitió el ticket.
    int day;                   // Día en el que se emitió el ticket.
    int idPicture;             // ID de la imagen asociada al ticket.
    int idCamara;              // ID de la cámara que tomó la foto.
    long long idOwner;         // ID del propietario del vehículo.
    std::string plate;         // Placa del vehículo.
    bool speedViolation;       // Indica si el ticket es por violación de velocidad.

public:
    // Constructor por defecto que inicializa todos los miembros con valores predeterminados.
    Ticket();

    // Constructor con parámetros que permite inicializar todos los miembros con valores específicos.
    Ticket(int year, int month, int day, int idPicture, int idCamara, long long idOwner,
           const std::string &plate, const std::string &name, bool speedViolation = false);

    // Métodos getter para obtener el valor de cada miembro de datos.
    int getYear() const;                 // Obtiene el año.
    int getMonth() const;                // Obtiene el mes.
    int getDay() const;                  // Obtiene el día.
    int getIdPicture() const;            // Obtiene el ID de la imagen.
    int getIdCamara() const;             // Obtiene el ID de la cámara.
    std::string getName() const;         // Obtiene el nombre del titular del ticket.
    long long getIdOwner() const;        // Obtiene el ID del propietario del vehículo.
    std::string getPlate() const;        // Obtiene la placa del vehículo.
    bool getSpeedViolation() const;      // Verifica si el ticket es por violación de velocidad.

    // Métodos setter para establecer el valor de cada miembro de datos.
    void setYear(int year);               // Establece el año.
    void setMonth(int month);            // Establece el mes.
    void setDay(int day);                // Establece el día.
    void setIdPicture(int idPicture);    // Establece el ID de la imagen.
    void setIdCamara(int idCamara);      // Establece el ID de la cámara.
    void setIdOwner(long long idOwner); // Establece el ID del propietario del vehículo.
    void setPlate(const std::string &plate); // Establece la placa del vehículo.
    void setName(const std::string &name);   // Establece el nombre del titular del ticket.
    void setSpeedViolation(bool violation);  // Establece si el ticket es por violación de velocidad.

    // Método que devuelve todos los datos del ticket como una cadena de texto.
    std::string getData() const;

    // Sobrecarga del operador << para imprimir el objeto Ticket en una salida de flujo.
    friend std::ostream& operator<<(std::ostream &out, const Ticket &ticket);

    // Sobrecarga de los operadores >, < y == para comparar objetos Ticket.
    bool operator>(const Ticket &other) const;  // Compara si el ticket es mayor que otro.
    bool operator<(const Ticket &other) const;  // Compara si el ticket es menor que otro.
    bool operator==(const Ticket &other) const; // Compara si el ticket es igual a otro.

};

#endif // TICKET_H

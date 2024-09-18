#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include "ticket.h"
#include "file.h"
#include "bst.h"

// Funciones para generar datos aleatorios

long long generateId() {
    return 1000000000 + (std::rand() % 1000000000); // Rango de 1000000000 a 1999999999
}

std::string generatePlate() {
    std::string plate;

    for (int i = 0; i < 3; ++i) {
        char randomLetter = 'A' + std::rand() % 26;
        plate += randomLetter;
    }

    int randomNumber = std::rand() % 1000;

    if (randomNumber < 10) {
        plate += "00" + std::to_string(randomNumber);
    } else if (randomNumber < 100) {
        plate += "0" + std::to_string(randomNumber);
    } else {
        plate += std::to_string(randomNumber);
    }

    return plate;
}

bool randomBool() {
    return std::rand() % 2 == 0;
}

// Función para validar la fecha
bool isValidDate(int year, int month, int day) {
    if (year < 1990 || year > 2024) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;
    if (month == 2) {
        if (day > 29) return false;
        if (day == 29 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))) return false;
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;
    return true;
}

// Función para verificar que la placa tenga el formato correcto
bool isValidPlate(const std::string& plate) {
    if (plate.size() != 6) return false;
    for (int i = 0; i < 3; ++i) {
        if (!isalpha(plate[i])) return false;
    }
    for (int i = 3; i < 6; ++i) {
        if (!isdigit(plate[i])) return false;
    }
    return true;
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(0))); // Inicializa la semilla para números aleatorios

    // Archivos de nombres que se usarán para obtener nombres aleatorios
    std::vector<std::string> files = {"Fnames.txt", "Mnames.txt"};
    // Años, meses y días válidos para la generación de tickets
    std::vector<int> years = {1990, 1992, 1994, 1996, 1998, 2000, 2002, 2004, 2006, 2008, 2010, 2012, 2014, 2016, 2018};
    std::vector<int> months = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    std::vector<int> days = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};

    File file;
    file.readFromFiles(files); // Lee nombres desde archivos

    // Crear un árbol binario de búsqueda para almacenar los tickets
    BinarySearchTree bst;

    // Generar tickets y agregarlos al árbol
    for (int i = 0; i < 356789; ++i) {
        int year = years[std::rand() % years.size()];
        int month = months[std::rand() % months.size()];
        int day = days[std::rand() % days.size()];
        int idPicture = std::rand() % 5000;
        int idCamara = std::rand() % 70;
        long long idOwner = generateId();
        std::string plate = generatePlate();
        std::string name = file.randomItem();
        bool speedViolation = randomBool();

        // Crear un ticket con los datos generados
        Ticket ticket(year, month, day, idPicture, idCamara, idOwner, plate, name, speedViolation);

        // Insertar el ticket en el árbol usando la matrícula como llave
        bst.insert(plate, ticket);
    }

    // Imprimir todos los tickets en orden
    bst.printInOrder();

    // Permitir al usuario ingresar datos para búsqueda
    for (int i = 0; i < 5; ++i) {

        std::string plate;
        int year, month, day;

        while (true) {
            std::cout << "Ingrese el número de placa (ejm: AAA000): ";
            std::cin >> plate;
            if (isValidPlate(plate)) break;
            std::cout << "Placa inválida. Por favor, ingrese la placa en el formato correcto (ejm: AAA000)." << std::endl;
        }

        while (true) {
            std::cout << "Ingrese la fecha en formato AÑO MES DÍA (ejm: 2019 3 17): ";
            std::cin >> year >> month >> day;
            if (isValidDate(year, month, day)) break;
            std::cout << "Fecha inválida. Por favor, ingrese la fecha en el formato correcto." << std::endl;
        }

        // Buscar el ticket en el árbol
        Ticket foundTicket = bst.search(plate);

        bool foundViolation = false;

        // Verificar si el ticket encontrado corresponde a la placa y fecha especificadas
        if (foundTicket.getPlate() == plate && foundTicket.getYear() == year &&
            foundTicket.getMonth() == month && foundTicket.getDay() == day) {
            if (foundTicket.getSpeedViolation()) {
                foundViolation = true;
                std::cout << "El vehículo con la placa " << plate << " tiene una multa por exceso de velocidad en la fecha " << year << "-" << month << "-" << day << "." << std::endl;
                std::cout << "Detalles del evento:" << std::endl;
                std::cout << "ID de la imagen: " << foundTicket.getIdPicture() << std::endl;
                std::cout << "ID de la cámara: " << foundTicket.getIdCamara() << std::endl;
                std::cout << "ID del propietario: " << foundTicket.getIdOwner() << std::endl;
                std::cout << "Nombre del propietario: " << foundTicket.getName() << std::endl;
            }
        }

        if (!foundViolation) {
            std::cout << "El vehículo con la placa " << plate << " no excedió la velocidad en ninguna de las 70 cámaras en la fecha " << year << "-" << month << "-" << day << "." << std::endl;
        }
    }
    return 0;
}

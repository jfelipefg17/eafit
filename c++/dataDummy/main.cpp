#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <random>
#include "ticket.h"
#include "file.h"
#include "bst.h"
#include "car.h"

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

int generateRandomNumber(int min, int max) {
    std::random_device rd;  // Generador aleatorio basado en hardware
    std::mt19937 gen(rd()); // Motor Mersenne Twister
    std::uniform_int_distribution<> distrib(min, max); // Distribución uniforme en el rango [min, max]
    return distrib(gen);
}


int main() {
    std::vector<std::string> files = {"Fnames.txt", "Mnames.txt"};
    std::vector<int> years = {1990, 1992, 1994, 1996, 1998, 2000, 2002, 2004, 2006, 2008, 2010, 2012, 2014, 2016, 2018};
    std::vector<int> months = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    std::vector<int> days = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};

    // Vector para almacenar los objetos Car
    std::vector<Car> cars;

    File file;
    file.readFromFiles(files); // Lee nombres desde archivos

    // Genera los carros
    for (int i = 0; i < 356789; ++i) {
        long long idOwner = generateId();
        std::string plate = generatePlate();
        std::string name = file.randomItem();

        Car car(idOwner, plate, name);
        cars.push_back(car);
    }

    // Vector para almacenar los tickets
    std::vector<Ticket> tickets;

    // Genera tickets en orden de fecha
    for (int year : years) {
        for (int month : months) {
            for (int day : days) {
                int numTickets = generateRandomNumber(1000, 2500);

                for (int i = 0; i < numTickets; ++i) {
                    int randomNumber2 = generateRandomNumber(0, cars.size() - 1); // Elige un carro al azar
                    Car selectedCar = cars[randomNumber2]; // Obtiene el carro aleatorio

                    int idPicture = std::rand() % 5000;
                    int idCamara = std::rand() % 70;
                    bool speedViolation = randomBool();

                    // Crea un ticket con el carro seleccionado
                    Ticket ticket(year, month, day, idPicture, idCamara, selectedCar, speedViolation);

                    // Añade el ticket a la lista de tickets
                    tickets.push_back(ticket);
                }
            }
        }
    }

    std::srand(static_cast<unsigned int>(std::time(0))); // Inicializa la semilla para números aleatorios



    // Imprimir los primeros 10 tickets generados
    std::cout << "Primeros 10 tickets generados:\n";
    for (size_t i = 0; i < 10 && i < tickets.size(); ++i) {
        std::cout << "Ticket " << i + 1 << ":\n";
        std::cout << "Fecha: " << tickets[i].getYear() << "-" << tickets[i].getMonth() << "-" << tickets[i].getDay() << "\n";
        std::cout << "ID de la imagen: " << tickets[i].getIdPicture() << "\n";
        std::cout << "ID de la cámara: " << tickets[i].getIdCamara() << "\n";
        std::cout << "Placa del vehículo: " << tickets[i].getCar().getPlate() << "\n";
        std::cout << "ID del propietario: " << tickets[i].getCar().getIdOwner() << "\n";
        std::cout << "Nombre del propietario: " << tickets[i].getCar().getName() << "\n";
        std::cout << "Multa por exceso de velocidad: " << (tickets[i].getSpeedViolation() ? "Sí" : "No") << "\n\n";
    }
    // Permitir al usuario ingresar datos para búsqueda
    for (int i = 0; i < 5; ++i) {
        std::string plate;
        int year, month, day;

        // Validar la placa ingresada
        while (true) {
            std::cout << "Ingrese el número de placa (ejm: AAA000): ";
            std::cin >> plate;
            if (isValidPlate(plate)) break;
            std::cout << "Placa inválida. Por favor, ingrese la placa en el formato correcto (ejm: AAA000)." << std::endl;
        }

        // Validar la fecha ingresada
        while (true) {
            std::cout << "Ingrese la fecha en formato AÑO MES DÍA (ejm: 2019 3 17): ";
            std::cin >> year >> month >> day;
            if (isValidDate(year, month, day)) break;
            std::cout << "Fecha inválida. Por favor, ingrese la fecha en el formato correcto." << std::endl;
        }

        // Buscar el ticket en la lista
        bool foundViolation = false;
        for (const Ticket& ticket : tickets) {
            if (ticket.getCar().getPlate() == plate && ticket.getYear() == year &&
                ticket.getMonth() == month && ticket.getDay() == day) {
                if (ticket.getSpeedViolation()) {
                    foundViolation = true;
                    std::cout << "El vehículo con la placa " << plate << " tiene una multa por exceso de velocidad en la fecha "
                              << year << "-" << month << "-" << day << "." << std::endl;
                    std::cout << "Detalles del evento:" << std::endl;
                    std::cout << "ID de la imagen: " << ticket.getIdPicture() << std::endl;
                    std::cout << "ID de la cámara: " << ticket.getIdCamara() << std::endl;
                    std::cout << "ID del propietario: " << ticket.getCar().getIdOwner() << std::endl;
                    std::cout << "Nombre del propietario: " << ticket.getCar().getName() << std::endl;
                }
            }
        }

        if (!foundViolation) {
            std::cout << "El vehículo con la placa " << plate << " no tiene una multa por exceso de velocidad en la fecha "
                      << year << "-" << month << "-" << day << "." << std::endl;
        }
    }

    return 0;
}

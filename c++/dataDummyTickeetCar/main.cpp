#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <random>
#include "ticket.h" // Incluye la definición de la clase Ticket.
#include "file.h"   // Incluye la clase para manejar archivos.
#include "car.h"    // Incluye la definición de la clase Car.

// Funciones para generar datos aleatorios
long long generateId() {
    return 1000000000 + (std::rand() % 1000000000); // Genera un ID aleatorio en el rango de 1000000000 a 1999999999.
}

std::string generatePlate() {
    std::string plate;

    // Genera las tres letras de la placa.
    for (int i = 0; i < 3; ++i) {
        char randomLetter = 'A' + std::rand() % 26; // Elige una letra aleatoria entre A y Z.
        plate += randomLetter; // Agrega la letra a la placa.
    }

    int randomNumber = std::rand() % 1000; // Genera un número aleatorio entre 0 y 999.

    // Formatea el número para que tenga siempre 3 dígitos.
    if (randomNumber < 10) {
        plate += "00" + std::to_string(randomNumber);
    } else if (randomNumber < 100) {
        plate += "0" + std::to_string(randomNumber);
    } else {
        plate += std::to_string(randomNumber);
    }

    return plate; // Retorna la placa generada.
}

bool randomBool() {
    return std::rand() % 2 == 0; // Retorna verdadero o falso aleatoriamente.
}

// Función para validar la fecha
bool isValidDate(int year, int month, int day) {
    if (year < 1990 || year > 2024) return false; // Valida el rango de años.
    if (month < 1 || month > 12) return false; // Valida el mes.
    if (day < 1 || day > 31) return false; // Valida el día.

    // Maneja la validación del mes de febrero.
    if (month == 2) {
        if (day > 29) return false; // Febrero no puede tener más de 29 días.
        if (day == 29 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))) return false; // Verifica si es un año bisiesto.
    }

    // Valida los meses que tienen 30 días.
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;

    return true; // La fecha es válida.
}

// Función para verificar que la placa tenga el formato correcto
bool isValidPlate(const std::string& plate) {
    if (plate.size() != 6) return false; // Verifica que la placa tenga 6 caracteres.
    for (int i = 0; i < 3; ++i) {
        if (!isalpha(plate[i])) return false; // Verifica que las tres primeras sean letras.
    }
    for (int i = 3; i < 6; ++i) {
        if (!isdigit(plate[i])) return false; // Verifica que los últimos tres sean dígitos.
    }
    return true; // La placa es válida.
}

// Genera un número aleatorio en un rango específico
int generateRandomNumber(int min, int max) {
    std::random_device rd;  // Generador aleatorio basado en hardware.
    std::mt19937 gen(rd()); // Motor Mersenne Twister.
    std::uniform_int_distribution<> distrib(min, max); // Distribución uniforme en el rango [min, max].
    return distrib(gen); // Retorna un número aleatorio en el rango especificado.
}

int main() {
    std::vector<std::string> files = {"Fnames.txt", "Mnames.txt"}; // Archivos de nombres.
    std::vector<int> years = {1990, 1992, 1994, 1996, 1998, 2000, 2002, 2004, 2006, 2008, 2010, 2012, 2014, 2016, 2018}; // Años válidos.
    std::vector<int> months = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; // Meses del año.
    std::vector<int> days = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31}; // Días del mes.

    // Vector para almacenar los objetos Car
    std::vector<Car> cars; // Almacena los coches generados.

    File file; // Crea un objeto de la clase File.
    file.readFromFiles(files); // Lee nombres desde los archivos.

    // Genera los coches
    for (int i = 0; i < 356789; ++i) { // Genera 356789 coches.
        long long idOwner = generateId(); // Genera un ID de propietario.
        std::string plate = generatePlate(); // Genera una placa aleatoria.
        std::string name = file.randomItem(); // Selecciona un nombre aleatorio.

        Car car(idOwner, plate, name); // Crea un objeto Car.
        cars.push_back(car); // Agrega el coche al vector.
    }

    // Vector para almacenar los tickets
    std::vector<Ticket> tickets; // Almacena los tickets generados.

    // Genera tickets en orden de fecha
    for (int year : years) { // Itera sobre los años.
        for (int month : months) { // Itera sobre los meses.
            for (int day : days) { // Itera sobre los días.
                int numTickets = generateRandomNumber(1000, 2500); // Genera un número aleatorio de tickets entre 1000 y 2500.

                for (int i = 0; i < numTickets; ++i) { // Genera los tickets.
                    int randomNumber2 = generateRandomNumber(0, cars.size() - 1); // Elige un coche al azar.
                    Car selectedCar = cars[randomNumber2]; // Obtiene el coche aleatorio.

                    int idPicture = std::rand() % 5000; // Genera un ID de imagen aleatorio.
                    int idCamara = std::rand() % 70; // Genera un ID de cámara aleatorio.
                    bool speedViolation = randomBool(); // Genera aleatoriamente si hay una violación de velocidad.

                    // Crea un ticket con el coche seleccionado.
                    Ticket ticket(year, month, day, idPicture, idCamara, selectedCar, speedViolation);

                    // Añade el ticket a la lista de tickets.
                    tickets.push_back(ticket);
                }
            }
        }
    }

    std::srand(static_cast<unsigned int>(std::time(0))); // Inicializa la semilla para números aleatorios.

    // Imprimir los primeros 10 tickets generados
    std::cout << "Primeros 10 tickets generados:\n";
    for (size_t i = 0; i < 10 && i < tickets.size(); ++i) { // Imprime los primeros 10 tickets.
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
    for (int i = 0; i < 5; ++i) { // Permite al usuario buscar 5 veces.
        std::string plate;
        int year, month, day;

        // Validar la placa ingresada
        while (true) {
            std::cout << "Ingrese el número de placa (ejm: AAA000): ";
            std::cin >> plate;
            if (isValidPlate(plate)) break; // Si la placa es válida, sale del bucle.
            std::cout << "Placa inválida. Por favor, ingrese la placa en el formato correcto (ejm: AAA000)." << std::endl;
        }

        // Validar la fecha ingresada
        while (true) {
            std::cout << "Ingrese la fecha en formato AÑO MES DÍA (ejm: 2019 3 17): ";
            std::cin >> year >> month >> day;
            if (isValidDate(year, month, day)) break; // Si la fecha es válida, sale del bucle.
            std::cout << "Fecha inválida. Por favor, ingrese la fecha en el formato correcto." << std::endl;
        }

        // Buscar el ticket en la lista
        bool foundViolation = false; // Bandera para verificar si se encontró una violación.
        for (const Ticket& ticket : tickets) { // Itera sobre todos los tickets.
            if (ticket.getCar().getPlate() == plate && ticket.getYear() == year &&
                ticket.getMonth() == month && ticket.getDay() == day) {
                if (ticket.getSpeedViolation()) { // Verifica si hay una violación de velocidad.
                    foundViolation = true; // Marca que se encontró una violación.
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

        if (!foundViolation) { // Si no se encontró ninguna violación.
            std::cout << "El vehículo con la placa " << plate << " no tiene una multa por exceso de velocidad en la fecha "
                      << year << "-" << month << "-" << day << "." << std::endl;
        }
    }

    return 0; // Fin del programa.
}

#include "person.h"  // Incluye el archivo de cabecera person.h
#include "file.h"    // Incluye el archivo de cabecera file.h
#include "node.h"    // Incluye el archivo de cabecera node.h
#include <cstdlib>   // Para std::rand y std::srand
#include <ctime>     // Para std::time
#include <vector>    // Para trabajar con arreglos dinámicos
#include <random>    // Para std::random_device, std::mt19937 y std::uniform_int_distribution
#include <iostream>  // Para std::cout y std::cin
#include <sstream>   // Para std::ostringstream

// Función para generar un ID numérico de 10 cifras en el rango especificado
long long generateId() {
    std::random_device rd;  // Dispositivo de generación de números aleatorios
    std::mt19937 gen(rd()); // Generador de números aleatorios Mersenne Twister
    std::uniform_int_distribution<long long> dis(1000000000, 1999999999); // Distribución uniforme en el rango deseado
    return dis(gen);
}

long long generatePhone() {
    std::random_device rd;  // Dispositivo de generación de números aleatorios
    std::mt19937 gen(rd()); // Generador de números aleatorios Mersenne Twister
    std::uniform_int_distribution<long long> dis(3000000000, 3239999999); // Distribución uniforme en el rango deseado
    return dis(gen);
}

#include <random>
#include <iomanip>
#include <sstream>

// Función para generar una estatura aleatoria redondeada a 2 decimales
double generateStature() {
    std::random_device rd;  // Dispositivo de generación de números aleatorios
    std::mt19937 gen(rd()); // Generador de números aleatorios Mersenne Twister
    std::uniform_real_distribution<double> dis(150.00, 199.99); // Distribución uniforme en el rango deseado
    double value = dis(gen);

    // Redondear a 2 decimales
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << value;
    stream >> value;
    return value;
}

// Función para generar un peso aleatorio redondeado a 2 decimales
double generateWeight() {
    std::random_device rd;  // Dispositivo de generación de números aleatorios
    std::mt19937 gen(rd()); // Generador de números aleatorios Mersenne Twister
    std::uniform_real_distribution<double> dis(40.0, 79.99); // Distribución uniforme en el rango deseado
    double value = dis(gen);

    // Redondear a 2 decimales
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << value;
    stream >> value;
    return value;
}

// Función para generar una dificultad aleatoria redondeada a 1 decimal
double generateDifficulty() {
    std::random_device rd;  // Dispositivo de generación de números aleatorios
    std::mt19937 gen(rd()); // Generador de números aleatorios Mersenne Twister
    std::uniform_real_distribution<double> dis(0.0, 7.9); // Distribución uniforme en el rango deseado
    double value = dis(gen);

    // Redondear a 1 decimal
    std::stringstream stream;
    stream << std::fixed << std::setprecision(1) << value;
    stream >> value;
    return value;
}

// Función para generar una ejecución aleatoria redondeada a 1 decimal
double generateExecution() {
    std::random_device rd;  // Dispositivo de generación de números aleatorios
    std::mt19937 gen(rd()); // Generador de números aleatorios Mersenne Twister
    std::uniform_real_distribution<double> dis(0.0, 7.9); // Distribución uniforme en el rango deseado
    double value = dis(gen);

    // Redondear a 1 decimal
    std::stringstream stream;
    stream << std::fixed << std::setprecision(1) << value;
    stream >> value;
    return value;
}


int main() {
    // Inicializar el generador de números aleatorios con el tiempo actual
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Lista de archivos de nombres: uno para hombres y otro para mujeres
    std::vector<std::string> files;
    files.push_back("Fnames.txt");
    files.push_back("Mnames.txt");

    // Crear un objeto File y leer los nombres desde los archivos
    File file;
    file.readFromFiles(files);


    // Crear un vector de objetos Node
    std::vector<Node> nodos;

    // Genera pregunta en consola de cuántas personas quiere generar
    int numPersonas;
    std::cout << "Ingrese el número de personas que desea generar: ";
    std::cin >> numPersonas;

    // Generar nodos con personas de nombres y edades aleatorias
    for (int i = 0; i < numPersonas; ++i) {
        std::string nombreAleatorio = file.randomItem();
        int edadAleatoria = 18 + std::rand() % 12; // Edad aleatoria entre 18 y 2 // Edad aleatoria entre 0 y 99
        long long idAleatorio = generateId();   // Generar un ID aleatorio de 10 cifras
        std::string gender = file.chooseGender(nombreAleatorio);
        std::string country = file.chooseCountry();
        std::string email = nombreAleatorio + "@gmail.com";
        long long phone = generatePhone();
        double stature = generateStature();
        double weight = generateWeight();
        double difficulty = generateDifficulty();
        double execution = generateExecution();
        Person personaAleatoria(nombreAleatorio, edadAleatoria, idAleatorio, gender, country, email, phone, stature, weight, difficulty, execution);
        nodos.emplace_back(personaAleatoria);
    }

    // Imprimir los datos de cada nodo
    for (const Node& nodo : nodos) {
        std::cout << nodo.getData() << std::endl;
    }

    //TODO a the same time that create a person insterted it in array, after that order it

    return 0;
}

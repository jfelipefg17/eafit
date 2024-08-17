#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <sstream>
#include "Person.h"
#include "File.h"

// Función para combinar dos mitades de un vector
void merge(std::vector<Person>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<Person> L(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<Person> R(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;

    // Combina los elementos de las dos mitades
    while (i < n1 && j < n2) {
        if (L[i].getTotalScore() >= R[j].getTotalScore()) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia los elementos restantes de la mitad izquierda
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia los elementos restantes de la mitad derecha
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Función de ordenamiento Merge Sort
void mergeSort(std::vector<Person>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Funciones para generar datos aleatorios

// Genera un ID aleatorio de 10 cifras
long long generateId() {
    return 1000000000 + std::rand() % 9000000000;
}

// Genera un número de teléfono aleatorio
long long generatePhone() {
    return 3000000000 + std::rand() % 999999999;
}

// Genera una estatura aleatoria en el rango [1.5, 2.5) metros
double generateStature() {
    return 1.5 + (std::rand() % 100) / 100.0;
}

// Genera un peso aleatorio en el rango [50, 150) kg
double generateWeight() {
    return 50 + (std::rand() % 100);
}

// Genera una dificultad aleatoria en el rango [0.0, 10.0)
double generateDifficulty() {
    return (std::rand() % 100) / 10.0;
}

// Genera una ejecución aleatoria en el rango [0.0, 10.0)
double generateExecution() {
    return (std::rand() % 100) / 10.0;
}

int main() {
    // Inicializar la semilla para la generación de números aleatorios
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Archivos para nombres de hombres y mujeres
    std::vector<std::string> files;
    files.push_back("Fnames.txt");
    files.push_back("Mnames.txt");

    // Leer nombres desde los archivos
    File file;
    file.readFromFiles(files);

    // Crear un vector para almacenar objetos Person
    std::vector<Person> nodos;

    int numPersonas;
    std::cout << "Ingrese el número de personas que desea generar: ";
    std::cin >> numPersonas;

    // Generar objetos Person con datos aleatorios
    for (int i = 0; i < numPersonas; ++i) {
        std::string nombreAleatorio = file.randomItem();
        int edadAleatoria = 18 + std::rand() % 12;
        long long idAleatorio = generateId();
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

    // Comenzar a medir el tiempo de ejecución
    auto start = std::chrono::high_resolution_clock::now();

    // Ordenar los objetos Person por su puntuación total
    mergeSort(nodos, 0, nodos.size() - 1);

    // Terminar de medir el tiempo de ejecución
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Sorting took " << duration.count() << " seconds." << std::endl;

    // Imprimir los 10 mejores gimnastas
    std::cout << "\nTop 10 Gymnasts:\n";
    for (int i = 0; i < std::min(10, static_cast<int>(nodos.size())); ++i) {
        std::cout << nodos[i].getData() << std::endl;
    }

    // Imprimir los 5 peores gimnastas
    std::cout << "\nBottom 5 Gymnasts:\n";
    for (int i = std::max(0, static_cast<int>(nodos.size()) - 5); i < nodos.size(); ++i) {
        std::cout << nodos[i].getData() << std::endl;
    }

    return 0;
}

#include "file.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <random>
#include <ctime>

// Método para leer datos desde archivos
// Lee nombres desde archivos especificados en el vector 'archivos' y los almacena en listas internas
// También lee el archivo 'country.txt' para obtener una lista de países
void File::readFromFiles(const std::vector<std::string> &archivos) {
    // Redimensiona 'nombresListas' para tener una lista por cada archivo
    nombresListas.resize(archivos.size());

    // Itera sobre cada archivo especificado
    for (size_t i = 0; i < archivos.size(); ++i) {
        std::ifstream archivo(archivos[i]);  // Abre el archivo
        std::string nombre;

        // Lee cada línea del archivo (cada nombre) y lo agrega a la lista correspondiente
        while (std::getline(archivo, nombre)) {
            nombresListas[i].insert(nombre);
        }
    }

    // Lee el archivo 'country.txt' para obtener la lista de países
    std::ifstream archivoPaises("country.txt");
    std::string pais;

    // Lee cada línea del archivo (cada país) y lo agrega a 'countries'
    while (std::getline(archivoPaises, pais)) {
        countries.push_back(pais);
    }
}

// Método para obtener un nombre aleatorio de las listas de nombres
// Selecciona aleatoriamente una lista de nombres y luego un nombre de esa lista
std::string File::randomItem() const {
    if (nombresListas.empty()) {
        return "";
    }

    // Selecciona aleatoriamente una lista de nombres
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> listaDis(0, nombresListas.size() - 1);
    size_t listaIndex = listaDis(gen);

    // Selecciona aleatoriamente un nombre de la lista seleccionada
    const std::set<std::string>& listaSeleccionada = nombresListas[listaIndex];
    std::uniform_int_distribution<size_t> nombreDis(0, listaSeleccionada.size() - 1);
    auto it = listaSeleccionada.begin();
    std::advance(it, nombreDis(gen));
    return *it;
}

// Método para determinar el género de una persona basado en el nombre
// Devuelve "Femenino" si el nombre se encuentra en la primera lista, "Masculino" si está en la segunda, o "Desconocido"
std::string File::chooseGender(const std::string &nombre) const {
    for (const auto& lista : nombresListas) {
        if (lista.find(nombre) != lista.end()) {
            return (lista == nombresListas[0]) ? "Femenino" : "Masculino";
        }
    }
    return "Desconocido";
}

// Método para elegir un país aleatorio de la lista de países
// Devuelve un país aleatorio si la lista no está vacía, o "Unknown" si está vacía
std::string File::chooseCountry() const {
    if (countries.empty()) {
        return "Unknown";
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> dis(0, countries.size() - 1);
    return countries[dis(gen)];
}

#include "file.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <random>
#include <ctime>

void File::readFromFiles(const std::vector<std::string> &archivos) {
    nombresListas.resize(archivos.size());

    for (size_t i = 0; i < archivos.size(); ++i) {
        std::ifstream archivo(archivos[i]);
        std::string nombre;
        while (std::getline(archivo, nombre)) {
            nombresListas[i].insert(nombre);
        }
    }

    // Leer el archivo country.txt
    std::ifstream archivoPaises("country.txt");
    std::string pais;
    while (std::getline(archivoPaises, pais)) {
        countries.push_back(pais);
    }
}

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

std::string File::chooseGender(const std::string &nombre) const {
    for (const auto& lista : nombresListas) {
        if (lista.find(nombre) != lista.end()) {
            return (lista == nombresListas[0]) ? "Femenino" : "Masculino";
        }
    }
    return "Desconocido";
}

std::string File::chooseCountry() const {
    if (countries.empty()) {
        return "Unknown";
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> dis(0, countries.size() - 1);
    return countries[dis(gen)];
}

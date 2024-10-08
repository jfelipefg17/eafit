#include "matrizAdyacencia.h"
#include <iostream>
#include <queue>
#include <stdexcept>

// Constructor
MatrizAdyacencia::MatrizAdyacencia() {}

// Destructor
MatrizAdyacencia::~MatrizAdyacencia() {
    // Liberar memoria de la matriz de adyacencia
    for (auto& fila : matrizAdyacencia) {
        for (auto& dato : fila) {
            delete dato;
        }
    }
}

// Método para agregar una ciudad (vértice)
void MatrizAdyacencia::agregarCiudad(const std::string& nombre, const std::string& pais, bool tieneAeropuerto) {
    // Agregar una nueva ciudad al vector y al mapa
    int id = ciudades.size();
    ciudades.emplace_back(id, nombre, pais, tieneAeropuerto);
    nombreCiudadAId[nombre] = id;

    // Ampliar la matriz de adyacencia
    for (auto& fila : matrizAdyacencia) {
        fila.emplace_back(nullptr);
    }
    matrizAdyacencia.emplace_back(ciudades.size(), nullptr);
}

// Método para agregar vuelos (aristas)
void MatrizAdyacencia::agregarVuelo(const std::string& ciudadOrigen, const std::string& ciudadDestino, int distancia, int duracion) {
    // Verificar la existencia de ciudades y validar reglas de vuelo
    auto itOrigen = nombreCiudadAId.find(ciudadOrigen);
    auto itDestino = nombreCiudadAId.find(ciudadDestino);

    if (itOrigen == nombreCiudadAId.end() || itDestino == nombreCiudadAId.end()) {
        throw std::runtime_error("Ciudad no encontrada");
    }

    // Se toma el id de las ciudades origen y destino
    int idOrigen = itOrigen->second;
    int idDestino = itDestino->second;

    // Se toman apuntadores de las ciudades origen y destino
    const Ciudad& origen = ciudades[idOrigen];
    const Ciudad& destino = ciudades[idDestino];

    if (!origen.getTieneAeropuerto() || !destino.getTieneAeropuerto()) {
        throw std::runtime_error("Una de las ciudades no tiene aeropuerto");
    }

    if (origen.getPais() == destino.getPais()) {
        throw std::runtime_error("No se permiten vuelos entre ciudades del mismo país");
    }

    // Agregar vuelo (arista) a la matriz de adyacencia
    matrizAdyacencia[idOrigen][idDestino] = new Data(distancia, duracion);
    matrizAdyacencia[idDestino][idOrigen] = new Data(distancia, duracion);
}

void MatrizAdyacencia::imprimirRedVuelos() const {
    // Imprimir información de vuelos internacionales para cada ciudad con aeropuerto
    for (int i = 0; i < ciudades.size(); ++i) {
        const Ciudad& ciudad = ciudades[i];
        if (ciudad.getTieneAeropuerto()) {
            std::cout << ciudad.getNombre() << " (" << ciudad.getPais() << "):" << std::endl;

            for (int j = 0; j < ciudades.size(); ++j) {
                if (matrizAdyacencia[i][j] != nullptr) {
                    const Ciudad& destino = ciudades[j];
                    const Data& data = *matrizAdyacencia[i][j];
                    std::cout << destino.getNombre() << " (" << destino.getPais()
                              << ")" << data.distancia << "km, " << data.duracion << "min" << std::endl;
                }
            }
            std::cout << std::endl;
        }
    }
}

void MatrizAdyacencia::BFS(const std::string& inicioCiudad) const {
    // Realizar un recorrido BFS desde la ciudad de inicio
    auto it = nombreCiudadAId.find(inicioCiudad);

    // Error si la ciudad no se encuentra en la matriz de adyacencia
    if (it == nombreCiudadAId.end()) {
        throw std::runtime_error("Ciudad de inicio no encontrada");
    }

    int idInicio = it->second; // Id de la ciudad de inicio
    std::vector<bool> visitado(ciudades.size(), false); // Vector de visitado)
    std::queue<int> cola; // cola que tendrá los ids de las ciudades que deberá visitarle a sus vecinos siguientes

    visitado[idInicio] = true;
    cola.push(idInicio);

    while (!cola.empty()) {
        int actual = cola.front();
        std::cout << ciudades[actual].getNombre() << " (" << ciudades[actual].getPais() << ")" << std::endl;
        cola.pop();

        // Visitamos las ciudades vecinas nuevas (los vecinos nuevos)
        for (int i = 0; i < ciudades.size(); ++i) {
            if (matrizAdyacencia[actual][i] != nullptr && !visitado[i]) {
                visitado[i] = true;
                cola.push(i);
            }
        }
    }
}

#include "person.h"  // Incluye el archivo de cabecera persona.h
#include "file.h"  // Incluye el archivo de cabecera archivo.h
#include "node.h"     // Incluye el archivo de cabecera node.h
#include <cstdlib>    // Para std::rand y std::srand
#include <ctime>      // Para std::time
#include <vector>     // Para trabajar con arreglos dinámicos

int main() {
    // Inicializar el generador de números aleatorios con el tiempo actual
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Crear un objeto Archivo y leer los nombres desde el archivo "nombres.txt"
    File file;
    file.leerDesdeArchivo("names.txt");

    // Crear un vector de objetos Node
    std::vector<Node> nodos;

    // Genera pregunta en consola de cuántas personas quiere generar
    int numPersonas;
    std::cout << "Ingrese el número de personas que desea generar: ";
    std::cin >> numPersonas;

    // Generar nodos con personas de nombres y edades aleatorias
    for (int i = 0; i < numPersonas; ++i) { // Generar numPersonas nodos como ejemplo
        std::string nombreAleatorio = file.obtenerItemAleatorio();
        int edadAleatoria = std::rand() % 100; // Edad aleatoria entre 0 y 99
        Person personaAleatoria(nombreAleatorio, edadAleatoria);
        nodos.emplace_back(personaAleatoria);
    }

    // Imprimir los datos de cada nodo
    for (const auto& nodo : nodos) {
        std::cout << nodo.getData() << std::endl;
    }

    return 0;
}
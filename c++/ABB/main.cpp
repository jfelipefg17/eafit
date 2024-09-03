#include "bst.h"     // Incluye el archivo de cabecera bst.h
#include <cstdlib>    // Para std::rand y std::srand
#include <string>     // Para trabajar con cadenas de texto
#include <vector>     // Para trabajar con arreglos dinámicos

int main() {
    // Inicializar el generador de números aleatorios con el tiempo actual
    std::srand(0);

    // Crear vector de nombres
    std::vector<std::string> nombres = {"Hugo", "Paco", "Luis", "Rosita"};

    // Crear un vector de objetos Node
    std::vector<Node> nodos;

    // Genera pregunta en consola de cuántas personas quiere generar
    int numPersonas;
    std::cout << "Ingrese el número de personas que desea generar: ";
    std::cin >> numPersonas;

    // Generar nodos con personas de nombres y edades aleatorias
    for (int i = 0; i < numPersonas; ++i) { // Generar numPersonas nodos como ejemplo
        std::string nombreAleatorio = nombres[std::rand() % nombres.size()]; // Nombre aleatorio de la lista
        int edadAleatoria = std::rand() % 101; // Edad aleatoria entre 0 y 100
        Persona personaAleatoria(nombreAleatorio, edadAleatoria);
        nodos.emplace_back(personaAleatoria);
    }

    // Imprimir los datos de cada nodo
    for (const auto& nodo : nodos) {
        std::cout << nodo.getData() << std::endl;
    }

    // Crear un árbol binario de búsqueda
    BST arbol = BST();

    // Insertar cada nodo en el árbol
    for (auto& nodo : nodos) {
        arbol.insert(nodo);
    }

    std::cout << "\n-----------------------------\n";

    // Imprimir el árbol en inorden
    arbol.printInOrden();

    std::cout << "\n-----------------------------\n";

    // Preguntar el tamaño del árbol
    cout << arbol.getSize() << endl;

    std::cout << "\n-----------------------------\n";

    // Preguntar el tamaño del árbol
    cout << arbol.search(66).getData() << endl;

    return 0;
}
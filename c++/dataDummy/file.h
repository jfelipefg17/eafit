#ifndef FILE_H
#define FILE_H

// Incluye las librerías estándar necesarias
#include <string>
#include <set>
#include <vector>

// Define la clase File que manejará la lectura y selección de nombres desde archivos.
class File {
private:
    // Vector que contiene conjuntos de nombres. Cada conjunto puede representar una lista de nombres (por ejemplo, masculinos y femeninos).
    std::vector<std::set<std::string> > nombresListas;

public:
    // Lee los nombres desde múltiples archivos y los almacena en listas.
    void readFromFiles(const std::vector<std::string>& archivos);

    // Obtiene un nombre aleatorio de las listas de nombres.
    std::string randomItem() const;
};

// Marca el final del bloque de definición para `FILE_H`, evitando inclusiones múltiples.
#endif // FILE_H

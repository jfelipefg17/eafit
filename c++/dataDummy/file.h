#ifndef FILE_H
#define FILE_H

#include <string>   // Para trabajar con palabras
#include <vector>   // Para trabajar con arreglos dinámicos
#include <fstream>  // Para trabajar con archivos
#include <cstdlib>  // Para std::rand y std::srand
#include <ctime>    // Para std::time

class File {
private:
    std::vector<std::string> items;

public:
    // Constructor
    File();

    // Método para leer los items desde un archivo
    void leerDesdeArchivo(const std::string& nombreArchivo);

    // Método para imprimir los items
    void imprimirItems() const;

    // Método para retornar un item aleatorio
    std::string obtenerItemAleatorio() const;
};

#endif // FILE_H
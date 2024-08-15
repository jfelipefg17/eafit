#include <iostream>
#include "file.h"

int main() {
    File lista;
    lista.leerDesdeArchivo("Fnames.txt");

    std::cout << "Items list:" << std::endl;
    lista.imprimirItems();

    std::cout << "Random list item: " << lista.obtenerItemAleatorio() << std::endl;

    return 0;
}
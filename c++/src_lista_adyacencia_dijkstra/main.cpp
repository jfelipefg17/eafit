#include "grafoListaAdyacencia.h"

#include <iostream>

// Función main para ejemplo de aplicación de Dijkstra
int main() {
    // Instanciar una lista de adyacencia
    ListaAdyacencia grafoLA;

    // Insertar en lista de adyacencia
    grafoLA.insertarNodo("libro", {{"lp", 5}, {"poster", 0}});
    grafoLA.insertarNodo("lp", {{"bajo", 15}, {"bateria", 20}});
    grafoLA.insertarNodo("bajo", {{"piano", 20}});
    grafoLA.insertarNodo("bateria", {{"piano", 10}});
    grafoLA.insertarNodo("poster", {{"bajo", 30}, {"bateria", 35}});

    grafoLA.mostrarListaAdyacencia();

    // Aplicar Dijkstra
    grafoLA.dijkstra("libro");

    // Mostrar padres
    grafoLA.mostrarPadres();

    // Mostrar costos
    grafoLA.mostrarCostos();

    return 0;
}
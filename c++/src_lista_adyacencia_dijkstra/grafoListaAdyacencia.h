#ifndef GRAFOLISTAADYACENCIA_H
#define GRAFOLISTAADYACENCIA_H

#include <unordered_map>
#include <string>
#include "dato.h"

// Importar biblioteca de lista ligada
#include <list>

// Instanciar una variable tipo lista ligada
typedef std::list<int> Lista;

// Algoritmo de ordenamiento burbuja sobre una lista ligada
void burbuja(Lista& lista);


// Clase de lista de adyacencia
class ListaAdyacencia {
    private:
        // diccionario con keys strings y value pares de string, int
        std::unordered_map<std::string, std::unordered_map<std::string, int>> listaAdyacencia;
        
        // Nodo de inicio para aplicar Dijkstra
        std::string nodoInicio;
        
        // Diccionario con key string y valor Dato
        std::unordered_map<std::string, std::string> padres;

        // Diccionario de costos con key nombre nodo y valor costo acumulado
        std::unordered_map<std::string, int> costos;

    public:
        // Constructor
        ListaAdyacencia();

        // Destructor
        ~ListaAdyacencia();

        // Método getter nodoInicio
        std::string getNodoInicio() const;

        // Método setters para insertar un nodo y sus vecinos y nodoInicio
        void insertarNodo(const std::string& nodo, const std::unordered_map<std::string, int>& vecinos);
        void setNodoInicio(const std::string& nodoInicio);

        // Método Dijkstra con parámetro nodoInicio que actualize padres y costos
        void dijkstra(const std::string& nodoInicio);

        // Método para mostrar la lista de adyacencia
        void mostrarListaAdyacencia() const;

        // Métodos mostrar padres y costos
        void mostrarPadres() const;
        void mostrarCostos() const;

        // Método mostrar camino ruta más corta desde nodoInicio a un nodoDestino
        void mostrarCamino(const std::string& nodoDestino) const;
};

#endif // GRAFOLISTAADYACENCIA_H
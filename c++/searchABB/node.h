#ifndef NODE_H
#define NODE_H

// Se incluyen las librerías necesarias y el archivo de definición de la clase Ticket.
#include <string>
#include "ticket.h"

// Se define la estructura Node para ser utilizada en el árbol binario de búsqueda.
struct Node {
    // La matrícula del vehículo, que actúa como la clave para la búsqueda en el árbol.
    std::string plate;

    // Un objeto Ticket asociado con la matrícula del vehículo.
    Ticket ticket;

    // Puntero al nodo hijo izquierdo del árbol.
    Node* left;

    // Puntero al nodo hijo derecho del árbol.
    Node* right;

    // Constructor de la estructura Node que inicializa la matrícula y el ticket.
    // Los punteros a los hijos se inicializan a nullptr.
    Node(const std::string& p, const Ticket& t)
        : plate(p), ticket(t), left(nullptr), right(nullptr) {}
};

// Fin de la definición del encabezado de Node.
#endif // NODE_H

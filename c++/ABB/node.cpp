#include "node.h"

// Constructor de Node que inicializa el nodo con un objeto Persona
Node::Node(const Persona &data) : data(data) {}

// Método getter para obtener el objeto Persona almacenado en el nodo
Persona Node::getData() const {
    return data;
}

// Método setter para modificar el objeto Persona almacenado en el nodo
void Node::setData(const Persona &data) {
    this->data = data;
}
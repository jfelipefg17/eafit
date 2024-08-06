#include "node.h"

// Constructor por defecto de Node, sin nombre ni edad válida
Node::Node() : data(Person("", -1)) {}

// Constructor de Node que inicializa el nodo con un objeto Persona
Node::Node(const Person &data) : data(data) {}

// Método getter para obtener el objeto Persona almacenado en el nodo
Person Node::getData() const {
    return data;
}

// Método setter para modificar el objeto Persona almacenado en el nodo
void Node::setData(const Person &data) {
    this->data = data;
}
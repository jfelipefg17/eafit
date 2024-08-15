#include "node.h"
#include <iostream>
#include <sstream>

// Constructor por defecto de Node, sin nombre ni edad válida
Node::Node() : data(Person("", -1, -1,"", "", "", -1, -0.1, -0.1, -0.1, -0.1)) {}

// Constructor de Node que inicializa el nodo con un objeto Persona
Node::Node(const Person &data) : data(data) {}

// Método getter para obtener el objeto Persona almacenado en el nodo
std::string Node::getData() const {
    std::ostringstream oss;
    oss << data;
    return oss.str();
}

// Método setter para modificar el objeto Persona almacenado en el nodo
void Node::setData(const Person &data) {
    this->data = data;
}

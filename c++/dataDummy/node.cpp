#include "node.h"
#include <iostream>
#include <sstream>

// Constructor por defecto de Node
// Inicializa el nodo con un objeto Person con valores predeterminados no válidos
Node::Node() : data(Person("", -1, -1, "", "", "", -1, -0.1, -0.1, -0.1, -0.1)) {}

// Constructor de Node que inicializa el nodo con un objeto Person
// Permite crear un nodo con una persona específica
Node::Node(const Person &data) : data(data) {}

// Método getter para obtener el objeto Person almacenado en el nodo
// Devuelve una representación textual de los datos de la persona contenida en el nodo
std::string Node::getData() const {
    std::ostringstream oss;
    oss << data;
    return oss.str();
}

// Método setter para modificar el objeto Person almacenado en el nodo
// Permite actualizar los datos de la persona en el nodo
void Node::setData(const Person &data) {
    this->data = data;
}

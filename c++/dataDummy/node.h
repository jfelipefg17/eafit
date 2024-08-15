#ifndef NODE_H
#define NODE_H

#include "person.h"

class Node {
private:
    Person data; // Objeto Persona almacenado en el nodo

public:
    // Constructor por defecto
    Node();

    // Constructor que inicializa el nodo con un objeto Persona
    Node(const Person &data);

    // Método getter para obtener el objeto Persona almacenado
    std::string getData() const;

    // Método setter para modificar el objeto Persona almacenado
    void setData(const Person &data);
};

#endif // NODE_H

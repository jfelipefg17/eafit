#ifndef NODE_H
#define NODE_H

#include "persona.h"

class Node {
private:
    Persona data; // Objeto Persona almacenado en el nodo
    
public:
    // Constructor que inicializa el nodo con un objeto Persona
    Node(const Persona &data);

    // Método getter para obtener el objeto Persona almacenado
    Persona getData() const;

    // Método setter para modificar el objeto Persona almacenado
    void setData(const Persona &data);

};

#endif // NODE_H
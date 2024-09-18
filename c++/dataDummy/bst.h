#ifndef BST_H
#define BST_H

#include "node.h"  // Incluye la definición de la estructura Node que se usará en el árbol.

class BinarySearchTree {
private:
    Node* root;  // Puntero al nodo raíz del árbol binario de búsqueda.

    // Método privado para insertar un nodo en el árbol.
    void insert(Node*& node, const std::string& plate, const Ticket& ticket);

    // Método privado para buscar un nodo en el árbol.
    Node* search(Node* node, const std::string& plate) const;

    // Método privado para imprimir los nodos del árbol en orden (recorrido in-order).
    void printInOrder(Node* node) const;

public:
    // Constructor por defecto que inicializa la raíz como nullptr.
    BinarySearchTree() : root(nullptr) {}

    // Destructor que liberará la memoria utilizada por el árbol.
    ~BinarySearchTree();

    // Método público para insertar un nuevo nodo en el árbol.
    void insert(const std::string& plate, const Ticket& ticket);

    // Método público para buscar un nodo por la placa y obtener el ticket asociado.
    Ticket search(const std::string& plate) const;

    // Método público para imprimir todos los nodos del árbol en orden.
    void printInOrder() const;

    // Método público para destruir el árbol a partir de un nodo.
    void destroyTree(Node* node);
};

#endif // BST_H

#include "bst.h"          // Incluye el archivo de encabezado que define la clase BinarySearchTree.
#include "ticket.h"       // Incluye el archivo de encabezado que define la clase Ticket.
#include <iostream>       // Incluye la biblioteca estándar para operaciones de entrada/salida.


// Destructor para liberar la memoria
BinarySearchTree::~BinarySearchTree() {
    destroyTree(root);
    // Llama al método destroyTree para liberar toda la memoria utilizada por el árbol.
}

void BinarySearchTree::destroyTree(Node* node) {
    if (node != nullptr) {
        destroyTree(node->left);   // Primero, libera recursivamente el subárbol izquierdo.
        destroyTree(node->right);  // Luego, libera recursivamente el subárbol derecho.
        delete node;               // Finalmente, libera el nodo actual.
    }
    // Este método asegura que todos los nodos sean eliminados y la memoria sea liberada.
}

void BinarySearchTree::insert(Node*& node, const std::string& plate, const Ticket& ticket) {
    if (node == nullptr) {
        node = new Node(plate, ticket);  // Si el nodo actual es nullptr, crea un nuevo nodo.
    } else if (plate < node->plate) {
        insert(node->left, plate, ticket);  // Si la placa es menor que la del nodo actual, inserta en el subárbol izquierdo.
    } else if (plate > node->plate) {
        insert(node->right, plate, ticket); // Si la placa es mayor que la del nodo actual, inserta en el subárbol derecho.
    }
    // Este método se encarga de insertar un nuevo nodo en el árbol manteniendo el orden.
}

Node* BinarySearchTree::search(Node* node, const std::string& plate) const {
    if (node == nullptr || node->plate == plate) {
        return node;  // Si el nodo es nullptr o la placa coincide con la del nodo actual, devuelve el nodo actual.
    }
    if (plate < node->plate) {
        return search(node->left, plate);  // Si la placa es menor, busca en el subárbol izquierdo.
    }
    return search(node->right, plate);  // Si la placa es mayor, busca en el subárbol derecho.
    // Este método busca un nodo con la placa dada y devuelve el nodo si lo encuentra.
}

void BinarySearchTree::insert(const std::string& plate, const Ticket& ticket) {
    insert(root, plate, ticket);
    // Llama al método insert que trabaja con un puntero a un nodo, usando la raíz del árbol.
}

Ticket BinarySearchTree::search(const std::string& plate) const {
    Node* result = search(root, plate);
    if (result != nullptr) {
        return result->ticket;  // Si se encuentra el nodo, devuelve el ticket asociado.
    }
    // Devuelve un ticket por defecto o inválido si no se encuentra el nodo.
    return Ticket();  // Suponiendo que el constructor por defecto de Ticket está definido.
}

void BinarySearchTree::printInOrder(Node* node) const {
    if (node != nullptr) {
        printInOrder(node->left);  // Imprime el subárbol izquierdo.
        std::cout << node->ticket << std::endl;  // Imprime el ticket del nodo actual.
        printInOrder(node->right);  // Imprime el subárbol derecho.
    }
    // Este método realiza un recorrido en orden del árbol, imprimiendo los tickets.
}

void BinarySearchTree::printInOrder() const {
    printInOrder(root);
    // Llama al método printInOrder que trabaja con un puntero a un nodo, usando la raíz del árbol.
}

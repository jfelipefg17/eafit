#include "bst.h"
#include <stdexcept> // Para std::invalid_argument

BST::BST() {
    root = nullptr;
    L = nullptr;
    R = nullptr;
    size = 0;
}

BST::~BST() {
    delete L;
    delete R;
}

void BST::insert(Node &node) {
    if (size == 0) root = &node;
    else if (node.getData() < root->getData() || node.getData() == root->getData()) {
        if (L == nullptr) L = new BST();
        L->insert(node);
    }
    else if (node.getData() > root->getData()) {
        if (R == nullptr) R = new BST();
        R->insert(node);
    }
    size++;
}

bool BST::isEmpty() const {
    if (size == 0) {
        return true;
    }
    else {
        return false;
    }
}

Node BST::search(const int edad) const {
    Node nodo_vacio = Node();

    if (size == 0) {
        return nodo_vacio;
    }

    if (edad == root->getData().getEdad()) {
        return *root;
    }
    else if (edad < root->getData().getEdad()) {
        if (L == nullptr) {
            return nodo_vacio;
        }
        return L->search(edad);
    }
    else {
        if (R == nullptr) {
            return nodo_vacio;
        }
        return R->search(edad);
    }
}

void BST::printInOrden() const {
    if (L != nullptr) L->printInOrden();                // Llamada recursiva al operador << para el subárbol izquierdo
    cout << "(" << root->getData() << "), ";
    if (R != nullptr) R->printInOrden();                // Llamada recursiva al operador << para el subárbol derecho
}

int BST::getSize() const {
    return size;
}

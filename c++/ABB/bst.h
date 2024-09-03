#ifndef BST_H
#define BST_H

#include "node.h"
#include <iostream>
#include <vector>    // Incluye la librería vector para usar vectores

using namespace std;

class BST {
private:
    Node *root;
    BST *L;
    BST *R;
    int size;

public:
    BST();                         // Constructor por defecto
    ~BST();                        // Destructor para liberar la memoria

    // Métodos para manipular el árbol binario de búsqueda
    void insert(Node &node);            // inserta un nodo en el árbol      
    bool isEmpty() const;               // verifica si el árbol está vacío
    // Node getRoot() const;               // Entrega el nodo raiz del árbol si existe
    // BST* getL() const;                  // Entrega el apuntador a subárbol izq del árbol si existe
    // BST* getR() const;                  // Entrega el apuntador a subárbol der del árbol si existe
    Node search(const int edad) const;  // busca un nodo en el árbol que coincida con la edad
    // void update(const Node &node);      // actualiza un nodo en el árbol
    // void remove(const Node &node);      // Busca un nodo y lo elimina del árbol
    void printInOrden() const;          // imprime el árbol en inorden
    // void printPreOrder() const;         // imprime el árbol en preorden
    // void printPostOrder() const;        // imprime el árbol en postorden
    // vector<Node *> getInOrder() const;  // retorna un vector con los nodos del árbol en orden ascendente (Inorden)
    // vector<Node *> getPreOrder() const; // retorna un vector con los nodos del árbol en preorden
    // vector<Node *> getPostOrder() const;// retorna un vector con los nodos del árbol en postorden
    int getSize() const;                // retorna el tamaño del Array
};

#endif // BST_H
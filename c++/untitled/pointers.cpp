#include <iostream>
using namespace std;
// without pointer
//void incrementarPorValor(int num) {
//    num += 1; // Incrementa la copia local de num
//}
//
//int main() {
//    int numero = 5;
//    incrementarPorValor(numero);
//    cout << "Valor después de incrementarPorValor: " << numero << endl; // Output: 5
//    return 0;
//}

// with pointer
void incrementarPorReferencia(int* numPtr) {
    *numPtr += 1; // Incrementa el valor al que apunta numPtr
}

int main() {
    int numero = 5;
    incrementarPorReferencia(&numero); // Pasa la dirección de 'numero' a la función
    cout << "Valor después de incrementarPorReferencia: " << numero << endl; // Output: 6
    return 0;
}
// todo g++ -o archivo archivo.cpp ./archivo
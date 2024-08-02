#include <iostream>
using namespace std;

// Función para mezclar dos subarreglos de arr[]
void merge(int arr[], int p, int q, int r) {
    // Encuentra el tamaño de los dos subarreglos para fusionar
    int n1 = q - p + 1;
    int n2 = r - q;

    // Crear arreglos temporales
    int L[n1], R[n2];

    // Copiar datos a los arreglos temporales L[] y R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];

    // Inicializar los índices de los subarreglos
    int i = 0;
    int j = 0;
    int k = p;

    // Fusionar los arreglos temporales de nuevo en arr[p..r]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[], si hay alguno
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[], si hay alguno
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Función principal que implementa MergeSort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Encuentra el punto medio para dividir el arreglo en dos mitades
        int m = l + (r - l) / 2;

        // Llama a mergeSort para la primera mitad
        mergeSort(arr, l, m);

        // Llama a mergeSort para la segunda mitad
        mergeSort(arr, m + 1, r);

        // Fusiona las dos mitades ordenadas
        merge(arr, l, m, r);
    }
}

// Función para imprimir un arreglo
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Función principal
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}

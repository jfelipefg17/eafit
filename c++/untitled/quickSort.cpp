#include <iostream>
using namespace std;

// Función para intercambiar dos elementos
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Función para encontrar la posición del pivote y particionar el array
int partition(int array[], int low, int high) {
    // Elegir el último elemento como pivote
    int pivot = array[high];
    // Índice del elemento más pequeño
    int i = low - 1;

    // Recorrer los elementos del array
    for (int j = low; j < high; j++) {
        // Si el elemento actual es menor o igual al pivote
        if (array[j] <= pivot) {
            // Incrementar el índice del elemento más pequeño
            i++;
            // Intercambiar los elementos
            swap(&array[i], &array[j]);
        }
    }

    // Intercambiar el pivote con el elemento en el índice i + 1
    swap(&array[i + 1], &array[high]);

    // Devolver el índice del pivote
    return (i + 1);
}

// Función principal que implementa QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Encontrar el índice del pivote y particionar el array
        int pivot = partition(arr, low, high);

        // Ordenar los elementos antes y después del pivote
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
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
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array is \n";
    printArray(arr, n);
    return 0;
}

#include <iostream>
#include <vector>

// Función para imprimir el arreglo
void imprimirArreglo(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// **Ordenamiento por Inserción (Insertion Sort)**
// Se inserta cada elemento en su posición correcta dentro de la lista ya ordenada.
// Complejidad:
// - Peor caso (Big O): O(n^2)
// - Mejor caso (Big Ω): Ω(n)
// - Caso promedio (Big Θ): Θ(n^2)
void insertionSort(std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;

        // Mover los elementos que son mayores que 'key' una posición adelante
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// **Ordenamiento por Selección (Selection Sort)**
// Se selecciona el elemento más pequeño y se intercambia con el primer elemento no ordenado.
// Complejidad:
// - Peor caso (Big O): O(n^2)
// - Mejor caso (Big Ω): Ω(n^2)
// - Caso promedio (Big Θ): Θ(n^2)
void selectionSort(std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        size_t minIdx = i;
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        std::swap(arr[i], arr[minIdx]);
    }
}

// **Ordenamiento Burbuja (Bubble Sort)**
// Se compara cada par de elementos adyacentes y se intercambian si están en el orden incorrecto.
// Complejidad:
// - Peor caso (Big O): O(n^2)
// - Mejor caso (Big Ω): Ω(n)
// - Caso promedio (Big Θ): Θ(n^2)
void bubbleSort(std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// **Ordenamiento por Mezcla (Merge Sort)**
// Divide el arreglo en dos mitades, las ordena recursivamente y luego las mezcla.
// Complejidad:
// - Peor caso (Big O): O(n log n)
// - Mejor caso (Big Ω): Ω(n log n)
// - Caso promedio (Big Θ): Θ(n log n)
void merge(std::vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
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

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int l, int r) {
    if (l >= r) {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

// **Ordenamiento Rápido (Quick Sort)**
// Selecciona un 'pivote', y reorganiza el arreglo de manera que los elementos menores estén antes y los mayores después.
// Complejidad:
// - Peor caso (Big O): O(n^2)
// - Mejor caso (Big Ω): Ω(n log n)
// - Caso promedio (Big Θ): Θ(n log n)
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    std::vector<int> arr = {64, 25, 12, 22, 11};

    std::cout << "Arreglo original: ";
    imprimirArreglo(arr);

    // **Insertion Sort**
    std::cout << "Ordenamiento por Inserción: ";
    insertionSort(arr);
    imprimirArreglo(arr);

    // Restablecer el arreglo original
    arr = {64, 25, 12, 22, 11};

    // **Selection Sort**
    std::cout << "Ordenamiento por Selección: ";
    selectionSort(arr);
    imprimirArreglo(arr);

    // Restablecer el arreglo original
    arr = {64, 25, 12, 22, 11};

    // **Bubble Sort**
    std::cout << "Ordenamiento Burbuja: ";
    bubbleSort(arr);
    imprimirArreglo(arr);

    // Restablecer el arreglo original
    arr = {64, 25, 12, 22, 11};

    // **Merge Sort**
    std::cout << "Ordenamiento por Mezcla: ";
    mergeSort(arr, 0, arr.size() - 1);
    imprimirArreglo(arr);

    // Restablecer el arreglo original
    arr = {64, 25, 12, 22, 11};

    // **Quick Sort**
    std::cout << "Ordenamiento Rápido: ";
    quickSort(arr, 0, arr.size() - 1);
    imprimirArreglo(arr);

    return 0;
}

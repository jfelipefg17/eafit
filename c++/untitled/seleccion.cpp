#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }

    for (int i = 0; i < n; ++i) {
        cout << "{" << arr[i] << "} ";
    }
    cout << endl;
}

int main() {
    int arr[] = {2, 5, 4, 6, 7, 8, 1, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);
    return 0;
}
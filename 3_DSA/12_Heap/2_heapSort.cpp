#include <iostream>
using namespace std;

// Heapify function for array for max heap (0-based indexing)
void heapify(int arr[], int n, int i) {
    int largest = i;
    int leftchild = 2 * i + 1;  
    int rightchild = 2 * i + 2; 

    if (leftchild < n && arr[largest] < arr[leftchild]) {
        largest = leftchild;
    }

    if (rightchild < n && arr[largest] < arr[rightchild]) {
        largest = rightchild;
    }

    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Step 1: Build the Max Heap (Rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {heapify(arr, n, i);} 

    // Step 2: One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);   // Note: We pass 'i' as the size, because we want to ignore elements after 'i'
    }
}

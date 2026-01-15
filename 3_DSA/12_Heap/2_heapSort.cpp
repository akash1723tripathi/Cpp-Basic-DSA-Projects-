#include <iostream>
using namespace std;


// Heapify function for array for max heap
void heapify(int arr[], int n, int i) {
      int largest = i;
      int leftchild = 2 * i;
      int rightchild = 2 * i + 1;

      // Adjust bounds for 1-based indexing
      if (leftchild <= n && arr[largest] < arr[leftchild]) {
            largest = leftchild;
      }
      if (rightchild <= n && arr[largest] < arr[rightchild]) {
            largest = rightchild;
      }

      if (largest != i) {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
      }
}

// Heapify function for array for min heap
// void heapify(int arr[], int n, int i) {
//     int smallest = i;
//     int leftchild = 2 * i;
//     int rightchild = 2 * i + 1;

//     // Adjust bounds for 1-based indexing
//     if (leftchild <= n && arr[smallest] > arr[leftchild]) {
//         smallest = leftchild;
//     }
//     if (rightchild <= n && arr[smallest] > arr[rightchild]) {
//         smallest = rightchild;
//     }

//     if (smallest != i) {
//         swap(arr[smallest], arr[i]);
//         heapify(arr, n, smallest);
//     }
// }

void heapSort(int arr[],int n){
      int size = n;

      while(size>1){
            // step-1: swap 
            swap(arr[size],arr[1]);
            size--;

            //step2 : heapify
            heapify(arr,size,1);
      }
}

int main(){
      // Heapify : heap creation
      int arr[6] = {-1, 60, 70, 55, 47, 50};  // Ensure array is 1-based
      int n = 5;                              // Size of the heap
      for (int i = n / 2 ; i > 0; i--) {       // Start from last non-leaf node     i=n/2-1 for min heap
        heapify(arr, n, i);
      }

      cout << "Printing the array: " << endl;
      for (int i = 1; i <= n; i++) {          // Print 1-based array
            cout << arr[i] << " ";
      } 
      cout << endl;

      heapSort(arr,n);
      cout << "Printing the array after sorting: " << endl;
      for (int i = 1; i <= n; i++) {          // Print 1-based array
            cout << arr[i] << " ";
      }

      return 0;

}
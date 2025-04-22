#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to heapify a subtree rooted at index i in a max heap
void heapify(vector<int>& heap, int n, int i) {
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    // Check if left child exists and is greater than root
    if (left < n && heap[left] > heap[largest])
        largest = left;

    // Check if right child exists and is greater than the largest so far
    if (right < n && heap[right] > heap[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(heap[i], heap[largest]);

        // Recursively heapify the affected subtree
        heapify(heap, n, largest);
    }
}

// Function to merge two max heaps
vector<int> mergeMaxHeaps(const vector<int>& heap1, const vector<int>& heap2) {
    // Step 1: Merge the two heaps into a single array
    vector<int> mergedHeap = heap1;
    mergedHeap.insert(mergedHeap.end(), heap2.begin(), heap2.end());

    // Step 2: Build a max heap from the merged array
    int n = mergedHeap.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(mergedHeap, n, i);
    }

    return mergedHeap;
}

// Utility function to print the heap
void printHeap(const vector<int>& heap) {
    for (int val : heap) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    // Example max heaps
    vector<int> heap1 = {10, 5, 6, 2};
    vector<int> heap2 = {8, 4, 7, 1};

    // Merge the heaps
    vector<int> mergedHeap = mergeMaxHeaps(heap1, heap2);

    // Print the result
    cout << "Merged Max Heap: ";
    printHeap(mergedHeap);

    return 0;
}

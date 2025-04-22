#include <iostream>
using namespace std;

class heap {
      public:
            int arr[100];
            int size;

            // Constructor
            heap() {
                  arr[0] = -1;
                  size = 0;
            }

            void insert(int val) {
                  size = size + 1;
                  int index = size;
                  arr[index] = val;

                  while (index > 1) {
                        int parent = index / 2;

                        if (arr[parent] < arr[index]) {
                        swap(arr[parent], arr[index]);
                        index = parent;
                        } else {
                        return;
                        }
                  }
            }

            void print() {
                  for (int i = 1; i <= size; i++) {
                        cout << arr[i] << " ";
                  }
                  cout << endl;
            }

            void deleteFromHeap() {
                  if (size == 0) {
                        cout << "Nothing can be deleted";
                        return;
                  }

                  // Replace first element with last
                  arr[1] = arr[size];

                  // Delete last element
                  size--;

                  // Propagate the new root to its correct position
                  int i = 1;
                  while (i <= size) {  // Fix condition
                        int leftindex = 2 * i;
                        int rightindex = 2 * i + 1;

                        if (leftindex <= size && arr[i] < arr[leftindex]) {
                        swap(arr[i], arr[leftindex]);
                        i = leftindex;
                        } else if (rightindex <= size && arr[i] < arr[rightindex]) {
                        swap(arr[i], arr[rightindex]);
                        i = rightindex;
                        } else {
                        return;
                        }
                  }
            }
};


int main() {
    heap h;
    h.insert(60);
    h.insert(70);
    h.insert(55);
    h.insert(67);
    h.insert(40);

    h.print();
    h.deleteFromHeap();
    h.print();

    return 0;
}

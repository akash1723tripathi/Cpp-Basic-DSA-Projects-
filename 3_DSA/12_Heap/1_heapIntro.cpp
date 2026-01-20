#include <iostream>
using namespace std;

class heap{
public:
      int arr[100];
      int size;

      // Constructor
      heap(){
            size = 0;
      }

      void insert(int val){
            // 1. Insert at the end (current size index)
            int index = size;
            arr[index] = val;
            size = size + 1;

            // 2. Propagate UP (Heapify Up)
            while (index > 0)
            {
                  int parent = (index - 1) / 2; // 0-based formula

                  if (arr[parent] < arr[index])
                  {
                        swap(arr[parent], arr[index]);
                        index = parent;
                  }
                  else
                  {
                        return;
                  }
            }
      }

      void print()
      {
            // Loop from 0 to size-1
            for (int i = 0; i < size; i++)
            {
                  cout << arr[i] << " ";
            }
            cout << endl;
      }

      void deleteFromHeap()
      {
            if (size == 0)
            {
                  cout << "Nothing can be deleted";
                  return;
            }

            // 1. Replace root (index 0) with last element
            arr[0] = arr[size - 1];
            size--; // Decrease size

            // 2. Propagate DOWN (Heapify Down)
            int i = 0;
            while (i < size)
            {
                  int leftIndex = 2 * i + 1;
                  int rightIndex = 2 * i + 2;
                  int largest = i; // Assume parent is largest initially

                  // Check if Left Child exists and is greater than current largest
                  if (leftIndex < size && arr[leftIndex] > arr[largest])
                  {
                        largest = leftIndex;
                  }

                  // Check if Right Child exists and is greater than current largest
                  if (rightIndex < size && arr[rightIndex] > arr[largest])
                  {
                        largest = rightIndex;
                  }

                  // If the largest is not the parent, swap and continue
                  if (largest != i)
                  {
                        swap(arr[i], arr[largest]);
                        i = largest; // Move pointer to where we just swapped
                  }
                  else
                  {
                        return; // Correct position found
                  }
            }
      }
};

int main()
{
      heap h;
      h.insert(60);
      h.insert(70);
      h.insert(55);
      h.insert(67);
      h.insert(40);

      cout << "Heap after insertion: ";
      h.print();

      h.deleteFromHeap();

      cout << "Heap after deletion:  ";
      h.print();

      return 0;
}
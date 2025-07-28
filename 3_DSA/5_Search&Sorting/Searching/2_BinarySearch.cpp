#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int target) {
int left = 0, right = arr.size() - 1;
      while (left <= right) {

            int mid = left + (right - left) / 2;
            if (arr[mid] == target)
                  return mid;
            else if (arr[mid] < target)
                  left = mid + 1; 
            else
                  right = mid - 1; 
      }
      return -1; 
      }

int main() {
      vector<int> arr = {2, 4, 8, 10, 20, 29};
      int target = 10;
      int index = binarySearch(arr, target);

      if (index != -1)
            cout << "Element found at index " << index << endl;
      else
            cout << "Element not found." << endl;

      /*
      ----------- Usage ---------------
      - Use when array is large and sorted.
      - Much faster than linear search for big datasets.

      ------------ Conditions -----------
      - Requires the array to be sorted in ascending order.

      ------------ Complexity -----------
      - Best case:    O(1)
      - Worst case:   O(log n)
      - Space:        O(1)

      ------------ Drawbacks ------------
      - Cannot be used on unsorted arrays.
      - Implementation for complex data types (custom comparisons) needs care.
      */
      return 0;
}

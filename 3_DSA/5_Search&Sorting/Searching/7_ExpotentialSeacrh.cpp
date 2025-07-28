#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(const vector<int>& arr, int left, int right, int target) {
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

// Exponential Search
int exponentialSearch(const vector<int>& arr, int target) {
      int n = arr.size();
      if (n == 0) return -1;
      if (arr[0] == target) return 0;

      // Find range for binary search
      int i = 1;
      while (i < n && arr[i] <= target)
            i = i * 2;

      // Binary search in found range
      return binarySearch(arr, i / 2, min(i, n - 1), target);
}

int main() {
      vector<int> arr = {2, 4, 8, 10, 20, 29};
      int target = 20;
      int index = exponentialSearch(arr, target);

      if (index != -1)
            cout << "Element found at index " << index << endl;
      else
            cout << "Element not found." << endl;

      /*
      ----------- Usage, Conditions, Drawbacks -------------
      - Use for very large or unknown-sized sorted arrays.
      - Very fast for elements near the start.
      - O(log i) time where i is index of target.
      - Requires random access, not for linked lists.
      */
      return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int interpolationSearch(const vector<int>& arr, int target) {
      int low = 0, high = arr.size() - 1;
      
      while (low <= high && target >= arr[low] && target <= arr[high]) {
            if (low == high) {
                  if (arr[low] == target) return low;
                  return -1;
            }
            int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]);
            if (arr[pos] == target)
                  return pos;
            if (arr[pos] < target)
                  low = pos + 1;
            else
                  high = pos - 1;
      }
      return -1;
}

int main() {
      vector<int> arr = {10, 15, 19, 21, 25, 28, 33};
      int target = 21;
      int index = interpolationSearch(arr, target);

      if (index != -1)
            cout << "Element found at index " << index << endl;
      else
            cout << "Element not found." << endl;

      /*
      ------------ Usage & Conditions -------------
      - Best for large, sorted, UNIFORMLY distributed numeric arrays.
      - Not reliable on non-uniform or unsorted data.

      ------------ Complexity --------------------
      - Average: O(log log n), Best: O(1), Worst: O(n)

      ------------- Drawbacks --------------------
      - Poor performance if data is non-uniformly distributed.
      - Risk of division by zero if arr[low] == arr[high].
      */
      return 0;
}

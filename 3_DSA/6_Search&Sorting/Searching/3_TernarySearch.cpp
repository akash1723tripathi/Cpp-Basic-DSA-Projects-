#include <iostream>
#include <vector>
using namespace std;


int ternarySearch(const vector<int>& arr, int left, int right, int target) {
      while (left <= right) {
            int mid1 = left + (right - left) / 3;
            int mid2 = right - (right - left) / 3;

            if (arr[mid1] == target)
                  return mid1;
            if (arr[mid2] == target)
                  return mid2;
                  
            if (target < arr[mid1])
                  right = mid1 - 1;
            else if (target > arr[mid2])
                  left = mid2 + 1;
            else
                  left = mid1 + 1, right = mid2 - 1;
      }
      return -1;
}

int main() {
      vector<int> arr = {2, 4, 8, 10, 20, 29};
      int target = 8;
      int index = ternarySearch(arr, 0, arr.size() - 1, target);

      if (index != -1)
            cout << "Element found at index " << index << endl;
      else
            cout << "Element not found." << endl;

      /*
      ------------- Usage & Conditions -----------
      - Use for unimodal or sorted arrays.
      - Rare in practice; binary search is usually preferred.

      ------------- Complexity ---------------
      - Worst/average: O(log3 n)
      - Space: O(1)

      ------------- Drawbacks -----------------
      - More comparisons per iteration than binary search; not always faster in practice.
      - Only suited for sorted arrays.
      */
      return 0;
}

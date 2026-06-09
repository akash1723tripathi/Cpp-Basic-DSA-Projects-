#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int jumpSearch(const vector<int>& arr, int target) {
      int n = arr.size();
      int step = sqrt(n); 
      int prev = 0;


      while (arr[min(step, n)-1] < target) {
            prev = step;
            step += sqrt(n);
            if (prev >= n)
                  return -1;
      }
      // Linear search in identified block
      for (int i = prev; i < min(step, n); ++i) {
            if (arr[i] == target)
                  return i;
      }
      return -1;
}

int main() {
      vector<int> arr = {1,3,5,8,12,19,22,27};
      int target = 12;
      int index = jumpSearch(arr, target);

      if (index != -1)
            cout << "Element found at index " << index << endl;
      else
            cout << "Element not found." << endl;

      /*
      ------------- Usage & Conditions --------------
      - Use for large, sorted arrays.
      - Works best when n is large and random access is fast.

      ------------- Complexity ---------------------
      - O(sqrt(n)) for both time and optimal block size.

      ------------- Drawbacks ----------------------
      - Less efficient than binary search for same scenario.
      - Only for sorted arrays.
      */
      return 0;
}

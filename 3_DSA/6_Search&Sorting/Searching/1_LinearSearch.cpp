      #include <iostream>
      #include <vector>
      using namespace std;

      int linearSearch(const vector<int>& arr, int target) {
      for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == target)
                  return i;
      }
      return -1;
      }

      int main() {
      vector<int> arr = {15, 3, 9, 8, 22, 10};
      int target = 8;
      int index = linearSearch(arr, target);

      if (index != -1)
            cout << "Element found at index " << index << endl;
      else
            cout << "Element not found." << endl;

      /*
      ----------------- Usage Notes -------------------
      - Use linear search when:
            - The array/list is unsorted or small.
            - No extra memory is allowed (O(1) space).
            - Simplicity is preferred over performance.

      ----------------- Conditions -------------------
      - No initial order or special structure required.
      - Works on any list, even with duplicate target values (returns first match).
      - Any comparable data type is supported.

      ----------------- Time Complexity -------------------
      - Best case:    O(1)    (target is at first index)
      - Average case: O(n)    (target is somewhere in the middle)
      - Worst case:   O(n)    (target is at the end or not present)

      ----------------- Drawbacks -------------------
      - Very inefficient for large datasets compared to binary search (which needs a sorted array).
      - Does not take advantage of array being sorted; performance always linear.
      - For huge arrays or performance-critical code, alternatives are preferred.
      */

      return 0;
}

#include <iostream>
#include <vector>
using namespace std;


int fibonacciSearch(const vector<int>& arr, int target) {
      int n = arr.size();
      int fibMMm2 = 0; 
      int fibMMm1 = 1; 
      int fibM = fibMMm2 + fibMMm1; 
      
      while (fibM < n) {
            fibMMm2 = fibMMm1;
            fibMMm1 = fibM;
            fibM = fibMMm2 + fibMMm1;
      }
      int offset = -1;

      while (fibM > 1) {
            int i = min(offset + fibMMm2, n - 1);
            if (arr[i] < target) {
                  fibM = fibMMm1;
                  fibMMm1 = fibMMm2;
                  fibMMm2 = fibM - fibMMm1;
                  offset = i;
            }
            else if (arr[i] > target) {
                  fibM = fibMMm2;
                  fibMMm1 = fibMMm1 - fibMMm2;
                  fibMMm2 = fibM - fibMMm1;
            }
            else
                  return i;
      }
      
      if (fibMMm1 && arr[offset + 1] == target)
            return offset + 1;
      return -1;
}

int main() {
      vector<int> arr = {2, 3, 4, 10, 40};
      int target = 10;
      int index = fibonacciSearch(arr, target);

      if (index != -1)
            cout << "Element found at index " << index << endl;
      else
            cout << "Element not found." << endl;

      /*
      ----------- Usage, Conditions, Drawbacks -------------
      - Use when array is sorted and division is costly (historically).
      - O(log n) time, O(1) space.
      - Less common today due to hardware advances; mainly educational use.
      */
      return 0;
}

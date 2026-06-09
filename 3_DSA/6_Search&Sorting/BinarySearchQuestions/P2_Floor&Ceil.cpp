//Brute Force Approach
//Time Complexity: O(n)
//Space Complexity: O(1)
int floor = -1, ceil = -1;
for (int i = 0; i < n; i++) {
    if (arr[i] <= x) floor = arr[i];
    if (arr[i] >= x) {
        ceil = arr[i];
        break;
    }
}


//Binary Search Approach
//Time Complexity: O(log n)
//Space Complexity: O(1)
#include <vector>
using namespace std;
int findFloor(vector<int>& arr, int x) {
      int low = 0, high = arr.size() - 1, ans = -1;
      while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= x) {  //lower bound condition
                  ans = arr[mid];  // potential floor
                  low = mid + 1;
            } else {
                  high = mid - 1;
            }
      }
      return ans;
}



int findCeil(vector<int>& arr, int x) {
      int low = 0, high = arr.size() - 1, ans = -1;
      while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= x) {  //reverse lower bound condition
                  ans = arr[mid];  // potential ceil
                  high = mid - 1;
            } else {
                  low = mid + 1;
            }
      }
      return ans;
}

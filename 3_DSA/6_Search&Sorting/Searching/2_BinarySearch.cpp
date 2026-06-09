#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
      int binarySearch(vector<int>& nums, int target) {
            int n = nums.size();
            if(n==1 && nums[n-1]==target){
                  return n-1;
            }
            int low = 0;
            int high = n-1;
            while(low<=high){
                  int mid = low + ((high-low)/2);
                  if(nums[mid]==target){
                  return mid;
                  }else if(nums[mid]>target){
                  high = mid-1;
                  }else{
                  low = mid+1;
                  }
            }
            return -1;
    }
};

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
// We will not use while loop for recursive approach
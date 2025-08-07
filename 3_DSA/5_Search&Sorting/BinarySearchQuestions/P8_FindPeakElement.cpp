class Solution {
public:
      int findPeakElement(vector<int>& nums) {
            int n = nums.size();
            int low = 0, high = n - 1;

            while (low < high) {
                  int mid = low + (high - low) / 2;

                  if (nums[mid] > nums[mid + 1]) {
                  // We're on a decreasing slope, so peak lies to the left (including mid)
                  high = mid;
                  } else {
                  // We're on an increasing slope, so peak lies to the right
                  low = mid + 1;
                  }
            }
            // low == high is the peak index
      return low;
      }
};




// My code 

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low=1,high=n-2;
        //if single element
        if(n==1){
            return 0;
        }
        //if leftmost
        if(nums[0]>nums[1]){
            return 0;
        }
        //if rightmost
        if(nums[n-1]>nums[n-2]){
            return n-1;
        }
        
        while(low<=high){
            int mid = low +((high-low)/2);
            if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid-1]<nums[mid]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }
};
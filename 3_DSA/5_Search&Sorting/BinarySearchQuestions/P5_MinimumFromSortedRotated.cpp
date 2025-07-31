class Solution {
public:
    int findMin(vector<int>& nums) {
            int n = nums.size();
            int low = 0,high=n-1;
            int ans = nums[low];

            while(low<=high){
                  int mid = low + ((high-low)/2);

                  //if both space are sorted
                  if(nums[low]<=nums[high]){
                        ans=min(ans,nums[low]);
                        break;
                  }

                  //left half sorted
                  if(nums[low]<=nums[mid]){
                        ans=min(ans,nums[low]);
                        low=mid+1;
                  }
                  //right sorted half
                  else{
                        ans=min(ans,nums[mid]);
                        high=mid-1;
                  }
            }
      return ans;
      }
};
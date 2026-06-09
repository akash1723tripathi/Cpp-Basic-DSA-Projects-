class Solution {
private:
      bool helper(vector<int>& nums, int threshold,int divisor,int n){
            int x=0,sum=0;
            for(int i=0;i<n;i++){
                  x = ceil((double)nums[i]/divisor);
                  // integer ceil = (nums[i]+divisor-1/divisor)
                  sum+=x;
            }
            if(sum<=threshold){
                  return true;
            }
      return false;
      }
public:
      int smallestDivisor(vector<int>& nums, int threshold) {
            int n = nums.size();
            int low=1;
            int high=*max_element(nums.begin(),nums.end());
            int ans=high;

            while(low<=high){
                  int mid = low + ((high-low)/2);
                  if(helper(nums,threshold,mid,n)==true){
                  ans=mid;
                  high=mid-1;
                  }
                  else{
                  low=mid+1;
                  }
            }
      return ans;
      }
};
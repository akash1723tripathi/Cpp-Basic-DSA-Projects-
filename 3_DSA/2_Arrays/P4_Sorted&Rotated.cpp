class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();

        //if the size of array is one return true then 
        if(n==1){
            return true;
        }

        //step-1:
        int i=1; // first index se traverse karunga 
        while(i<n && nums[i]>=nums[i-1]) {
            i++;
        }

        // if reached to the end  
        if(i == n)  return true;

        // if we encounter such a element which is decreasing/strictly increasing  
        if(nums[i]>nums[0])  return false;

        //only observed the increasing curve 
        if(i==n-1) return true;

        //step-2
        //for the second non dcreasing curve
        i+=1;
        while(i<n && nums[i]>=nums[i-1] && nums[i]<=nums[0] ){
            i++;
        }
        //second curve ke end tak pahuch gaye ho tab 
        return i==n;
    }
};
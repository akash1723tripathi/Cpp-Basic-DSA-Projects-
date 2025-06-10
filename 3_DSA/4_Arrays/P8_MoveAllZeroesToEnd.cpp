class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j,i=-1;
        int n = nums.size();
        //to finf the first zero from the given array
        for(auto i=0;i<n;i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }

        // to swap the elements 
        for(int i=j+1;i<n;i++){
            if(nums[i]!=0){
                int temp=nums[j];
                nums[j]=nums[i];
                nums[i]=temp;
                j++;
            }
        }
    }
};
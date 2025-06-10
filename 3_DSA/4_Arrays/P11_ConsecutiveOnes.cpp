
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                cnt++;
            }else{
                maxi = max(cnt,maxi);
                cnt=0;
            }
        }
        //if i don`t get a zero --trailing ones
        maxi = max(cnt, maxi);
        return maxi;
    }
};
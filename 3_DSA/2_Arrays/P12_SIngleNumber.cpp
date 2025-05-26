class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int XOR1=0;
        for(int i=0;i<nums.size();i++){
            XOR1 = XOR1^nums[i];
        }
        return XOR1;
    }
};
class Solution {
public:
      vector<int> singleNumber(vector<int>& nums) {
            long long res = 0;
            for(int val : nums){
                  res = res ^ val;
            }
            long long rightMost = (res & -res);
      
            int b1 = 0, b2 = 0;
            for(int val : nums){
                  if(val & rightMost) {
                  b1 = b1 ^ val;
                  } else {
                  b2 = b2 ^ val;
                  }
            }
            
            if(b1 < b2) return {b1, b2};
            return {b2, b1};
      }
};
class Solution {
public:
      vector<int> rearrangeArray(vector<int>& nums) {
            vector<int> ans(nums.size());
            int pos = 0,neg=1;
            for(int i=0;i<nums.size();i++){
                  int tmp = nums[i];
                  if(tmp>=0){
                  ans[pos]=tmp;
                  pos=pos+2;
                  }
                  if(tmp<0){
                  ans[neg]=tmp;
                  neg=neg+2;
                  }
            }
            return ans;
      }
};
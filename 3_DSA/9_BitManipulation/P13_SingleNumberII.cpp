//when 3 are reapetating we can use the same map based appraoch but xor will not work here

//using map
class Solution {
public:
      int singleNumber(vector<int>& nums) {
            unordered_map<int,int> mp;
            for(int i:nums){
                  mp[i]++;
            }
            for(auto it : mp ){
                  if(it.second==1){
                  return it.first;
                  }
            }
            return 0;
      }

};


//using bit manipulation

class Solution {
public:
      int singleNumber(vector<int>& nums) {
            int ans=0;
            for(int bitIndex=0;bitIndex<32;bitIndex++){
                  int cnt=0;
                  for(int i=0;i<nums.size();i++){
                  if(nums[i]&(1<<bitIndex)) cnt++;
                  }
            if(cnt%3==1) ans=ans|(1<<bitIndex);
            }
            return ans;
      }

};   


//using buckets
class Solution {
public:
      int singleNumber(vector<int>& nums) {
            int ones=0,twos=0;
            for(int i=0;i<nums.size();i++){
                  ones = (ones^nums[i])&(~twos);
                  twos = (twos^nums[i])&(~ones);
            }
            return ones;
      }

};
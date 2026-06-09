//when 2 elements are reapeating 

//Map based approach
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




//Xor based approach
class Solution {
  public:
      int getSingle(vector<int>& arr) {
            int n= arr.size();
            int res=0;
            for(int i:arr){
                  res=res^i;
            }
            return res;
            
      }
};



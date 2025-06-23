// for an arr to return indices of the elements which adds up to given target

// best for to return indecies--use map ---> worst O(n^2)
class Solution
{
public:
      vector<int> twoSum(vector<int> &nums, int target){
            map<int, int> mpp;
            int n = nums.size();
            for (int i = 0; i < n; i++){
                  int fnum = nums[i];
                  int snum = target - fnum;
                  if (mpp.find(snum) != mpp.end()){
                        return {mpp[snum], i};
                  }
                  mpp[fnum] = i;
            }
            return {-1, -1};
      }
};

// optimal-- O(n)
class Solution {
public:
      vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> complements;
      for (int i = 0; i < nums.size(); ++i) {
          int num = nums[i];
            if (complements.count(num)) {
                  return {complements[num], i};
            }
            complements[target - num] = i;
      }
      return {};
      }
};


//for scenarios to return yes/no ---> O(N)
class Solution {
public:
      vector<int> twoSum(vector<int>& nums, int target) {
            int n = nums.size();
            sort(nums.begin(),nums.ens());
            int left = nums[0];
            int right = nums[n-1];

            while(left<right){
                  int sum = left+right;
                  if(sum>target){
                        right--;
                  }
                  if(sum<target){
                        left++;
                  }
                  if(sum==target){
                        return true;
                  }
            }
            return false;
      }
};
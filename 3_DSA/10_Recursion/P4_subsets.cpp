class Solution {
private:
    vector<vector<int>> ans;

    void sol(int idx, vector<int> curr, vector<int>& nums){
        if(idx==nums.size()){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[idx]);
        sol(idx+1,curr,nums);
        curr.pop_back();
        sol(idx+1,curr,nums);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int idx=0;
        vector<int>curr;
        sol(idx,curr,nums);
        return ans;
    }
};
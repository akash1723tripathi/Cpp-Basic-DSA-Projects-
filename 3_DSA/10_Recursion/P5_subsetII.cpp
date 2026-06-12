class Solution {
public:
    
    vector<vector<int>> ans;
    
    void solve(int index,
               vector<int>& nums,
               vector<int>& current)
    {
        // Every state is a valid subset
        ans.push_back(current);

        for(int i = index; i < nums.size(); i++)
        {
            // Skip duplicates at the same level
            if(i > index && nums[i] == nums[i - 1])
                continue;
            current.push_back(nums[i]);
            solve(i + 1, nums, current);
            current.pop_back(); // backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> current;
        solve(0, nums, current);
        return ans;
    }
};
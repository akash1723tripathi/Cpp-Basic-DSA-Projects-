class Solution {
public:

    vector<vector<int>> ans;

    void solve(int index, vector<int>& candidates, int target, vector<int>& current){
        // Exact target achieved
        if(target == 0){
            ans.push_back(current);
            return;
        }

        // Out of bounds
        if(index == candidates.size())
            return;

        // Pick current element
        if(candidates[index] <= target){
            current.push_back(candidates[index]);
            solve(index, candidates, target - candidates[index], current);
            current.pop_back();
        }

        // Don't pick current element
        solve(index + 1, candidates, target, current);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        vector<int> current;
        solve(0, candidates, target, current);
        return ans;
    }
};
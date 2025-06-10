// approach 2
class Solution {
private: 
    void InorderTraversal(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;
        InorderTraversal(root->left, ans);
        ans.push_back(root->val);
        InorderTraversal(root->right, ans);
    }

public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        InorderTraversal(root, ans);

        int i = 0, j = ans.size() - 1;
        while (i < j) {
            int sum = ans[i] + ans[j];
            if (sum == k) return true;  
            if (sum > k) {
                j--;  
            } else {
                i++;  
            }
        }
        return false;
    }
};

// approach 3 
class Solution {
private:
    TreeNode* helper(vector<int>& preorder, int min, int max, int& i) {
        if (i >= preorder.size() || preorder[i] < min || preorder[i] > max) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = helper(preorder, min, root->val, i);
        root->right = helper(preorder, root->val, max, i);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return helper(preorder, INT_MIN, INT_MAX, i);
    }
};

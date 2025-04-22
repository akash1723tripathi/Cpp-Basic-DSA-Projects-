class Solution {
private: 
    bool validateBST(TreeNode* root, long min, long max) {
        if (root == NULL) return true;

        if (root->val > min && root->val < max) {
            bool left = validateBST(root->left, min, root->val);
            bool right = validateBST(root->right, root->val, max);
            return left && right;
        } else {
            return false;
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        return validateBST(root, LONG_MIN, LONG_MAX);
    }
};
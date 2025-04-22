class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(root->val == p->val || root->val== q->val){
            return root;
        }
        TreeNode* leftAns =lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAns =lowestCommonAncestor(root->right,p,q);

        if(leftAns != NULL && rightAns != NULL)   return root;
        else if (leftAns != NULL && rightAns == NULL) return leftAns;
        else if(leftAns == NULL && rightAns != NULL) return rightAns;
        else return NULL;
    }
};


class Solution {
public:
      TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if (!root || root == p || root == q) return root;
            TreeNode* left = lowestCommonAncestor(root->left, p, q);
            TreeNode* right = lowestCommonAncestor(root->right, p, q);
            return !left ? right : !right ? left : root;
      }
};
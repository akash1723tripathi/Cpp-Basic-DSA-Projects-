//approach 1 ----O(n*n)

class Solution {

private:
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        return 1+ max(maxDepth(root->left),maxDepth(root->right));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL){
            return 0;
        }
        int op1 = diameterOfBinaryTree(root->left);
        int op2 = diameterOfBinaryTree(root->right);
        int op3 = maxDepth(root->left) + maxDepth(root->right);

        int ans = max(op1, max(op2,op3));
        return ans;

    }
};


// approach 2

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        result = 0;
        height(root);
        return result;
    }

    int height(TreeNode* root)
    {
        if (!root)
            return 0;

        int left = height(root->left);
        int right = height(root->right);

        result = max(result, left+right);
        return max(left, right)+1;
    }

    int result;

};


// approach 3

class Solution {

private:
    pair<int,int> diameterfast(TreeNode* root){
        if(root==NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        pair<int,int> left = diameterfast(root->left);
        pair<int,int> right = diameterfast(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second ;

        pair<int,int> ans;
        ans.first = max(op1, max(op2,op3));
        ans.second = max(left.second, right.second)+1;
        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return diameterfast(root).first;

  }
};
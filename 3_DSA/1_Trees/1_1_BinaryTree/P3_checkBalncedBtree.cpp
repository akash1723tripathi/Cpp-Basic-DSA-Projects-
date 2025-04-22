//approach 1  O(n*N)
class Solution {
public:
     int isbalanced( TreeNode* root){
        if (!root) return 0;
        int left=isbalanced(root->left);
        int right=isbalanced(root->right);
        if(left==-1 || right==-1 || abs(left-right)>1) return -1;
        return 1+max(left,right);
     }
    bool isBalanced(TreeNode* root) {
        return isbalanced(root)!=-1;
    }
};

//approach 2   o(n)
class Solution {
public:
    pair<bool,int> isbalanced(TreeNode* root){
        if(root==NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        pair<bool,int> left = isbalanced(root->left);
        pair<bool,int> right = isbalanced(root->right);

        bool leftAns = left.first;
        bool rightAns = right.first;
        bool diff = abs(left.second - right.second)<=1;

        pair<bool,int> ans;
        ans.second = max(left.second,right.second) +1;

        if(leftAns && rightAns && diff){
            ans.first = true;
        }
        else{
            ans.first = false;
        }
        return ans;
    }

    bool isBalanced(TreeNode* root) {
        return isbalanced(root).first;
    }
};
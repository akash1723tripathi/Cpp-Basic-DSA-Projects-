//Approach 1

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr!= NULL){
            if(curr->left){
                TreeNode* pred= curr->left;
                while(pred->right){
                    pred=pred->right;
                }
                pred->right= curr->right;
                curr->right= curr->left;
            }
            curr=curr->right;
        }
        curr = root;
        while(curr != NULL){
            curr->left = NULL;
            curr = curr->right;
        }
    }
};


//Approach 2

class Solution {
private:
    TreeNode* prev = nullptr;

public:
    void flatten(TreeNode* root) {
        if (!root) return;

        // Process right subtree first
        flatten(root->right);

        // Process left subtree
        flatten(root->left);

        // Set the current node's right to prev and left to null
        root->right = prev;
        root->left = nullptr;

        // Update prev to current node
        prev = root;
    }
};
// predecessor and successor in BST 

class Solution{
public:
      pair<int,int> predecessorSuccessorBST(TreeNode* root, int key){
        TreeNode* temp = root;
        int pred = -1;
        int succ = -1;

        while(temp->data != key){
            if(temp->data > key){
                  succ = temp->data;
                  temp=temp->left;
            }
            else{
                  pred = temp->value;
                  temp = temp->right;
            }
        }    

        TreeNode* leftTree = temp->left;
        while(leftTree != NULL ){
            pred = leftTree->val;
            leftTree=leftTree->right;
        }

        TreeNode* rightTree = temp->right;
        while(rightTree != NULL ){
            pred = rightTree->val;
            rightTree=rightTree->left;
        } 

        pair<int,int> ans = make_pair(pred,succ);
        return ans;      
      }
};
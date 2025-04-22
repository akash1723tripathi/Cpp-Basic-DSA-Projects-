// conversion of BST to Singly LL 
class solution{
private:
      void inorderTraversal(TreeNode* root, vector<int> &ans){
            if(root == NULL) return ;

            inorderTraversal(root->left,ans);
            ans.push_back(root->val);
            inorderTraversal(root->right, ans);
      }
public:
      TreeNode* flattenBST(TreeNode* root){
            vector<int> ans;
            inorderTraversal(root,ans);
            int n = ans.size();
            TreeNode* newRoot = new TreeNode(ans[0]);
            TreeNode* curr = newRoot;

            for(int i=1;i<n;i++){
                  TreeNode* temp = new TreeNode(ans[i]);
                  curr->left=NULL;
                  curr->right= temp;
                  curr=temp;
            }

            curr->left = NULL;
            curr->right = NULL;

            return newRoot;

      }
};


// converison of BST into Doubly LL
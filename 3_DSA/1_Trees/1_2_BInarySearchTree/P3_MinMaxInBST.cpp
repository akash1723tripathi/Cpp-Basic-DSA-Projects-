TreeNode* MinVal(TreeNode* root){
      TreeNode* temp = root;
      while( temp->left != NULL){
            temp=temp->left;
      }
      return temp;
}

TreeNode* MaxVal(TreeNode* root){
      TreeNode* temp = root;
      while( temp->right != NULL){
            temp=temp->right;
      }
      return temp;
}
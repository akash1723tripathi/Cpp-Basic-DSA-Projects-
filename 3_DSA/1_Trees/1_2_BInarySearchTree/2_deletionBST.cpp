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


Node* deleteFromBST(Node* root, int val){
      if(root==NULL) return NULL;
      if(root->data == val){
            // 0 child
            if(root->left == NULL && root->right == NULL){
                  delete root;
                  return NULL;
            }
            // 1 child
                  // left child
            if(root->left != NULL && root->right == NULL){
                  Node* temp = root->left;
                  delete root;
                  return temp;
            }
                  //right child
            if(root->left == NULL && root->right != NULL){
                  Node* temp = root->right;
                  delete root;
                  return temp;
            }

            //2 child
            if(root->left != NULL && root->right != NULL){
                  //either minimum from right or maximum from left
                  int max_val = MaxVal(root->left);
                  root->data = max_val;
                  root->left = deleteFromBST(root->left, max_val);
                  return root;
            }

            
      }else if(root->data > val){
            root->left = deleteFromBST(root->left,val);
            return root;
      }
      else{
            root->right =deleteFromBST(root->right,val);
            return root;
      }
      return root;
}

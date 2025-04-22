class solution {
      public: 
            void TraverseLeft(Node* root, vector<int> &ans){
                  if((root==NULL)|| (root->left == NULL && root->right==NULL))
                        return;

                  ans.push_back(root->data);
                  if(root->left)
                        TraverseLeft(root->left,ans);
                  else
                        TraverseLeft(root->right,ans);      
            }

            void traverseLeaf(Node* root, vector<int. &ans){
                  if(root==NULL) return;
                  if(root->left == NULL && root->right == NULL)  {
                        ans.push_back(root->data);
                  }

                  traverseLeaf(root->left,ans);
                  traverseLeaf(root->right,ans);
            }

            void TraverseRight(Node* root, vector<int> &ans){
                  if((root==NULL)|| (root->left == NULL && root->right==NULL))   return;

                  if(root->right){
                        TraverseRight(root->right,ans);
                  }else{
                        TraverseRight(root->left,ans);
                  }
            }

            vector<int> boundary(Node* root){
                  vector<int> ans;
                  if(root==NULL)
                        return ans;

                  ans.push_back(root->data);

                  //traverseleft
                  TraverseLeft(root->left); 

                  traverseLeaf(root->left,ans);     
                  traverseLeaf(root->right,ans);

                  TraverseRight(root->right);     
            }      
};
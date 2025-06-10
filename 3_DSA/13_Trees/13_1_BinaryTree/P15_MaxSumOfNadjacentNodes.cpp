class solution {
      public :
            pair<int,int> helper(Node* root){
                  if(root==NULL) {
                        pair<int,int> p = make_pair(0,0);
                        return p;
                  }

                  pair<int,int> left = helper(root->left);
                  pair<int,int> right = helper(root->right);

                  pair<int,int> res;
                  res.first = (root->data + left.second + right.second);
                  res.second = max(left.first, left.second) + max(right.first , right.second);
                  return res;
            }


            int getMaxSum(Node* root){
                  pair<int,int> ans = helper();
                  return max(ans.first,ans.second);
            }
}
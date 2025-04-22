//appraoch 1 : for 2 BST 
class Solution{
private: 
      void inorder(TreeNode* root, vector<int> &ans){
            if(root==NULL){
                  return;
            }
            inorder(root->left,ans);
            ans.push_back(root->val);
            inorder(root->right,ans);
      }

      vector<int> mergeArr(vector<int> a,vector<int> b ){
            vector<int> ans(a.size()+b.size());

            int i,j,k = 0;
            while(i<a.size() && j<b.size()){
                  if(a[i]<b[i]){
                        ans[k++] = a[i];
                  }else{
                        ans[k++] = b[j];
                  }
            }
            while(i<a.size()){
                  ans[k++]=a[i];
                  i++;
            }
            while(j<b.size()){
                  ans[k++]=b[j];
                  j++;
            }
            return ans;
            
      }

      TreeNode* normalToBalanced(int start, int end, vector<int> &mergeArray){
            if(start>end){
                  return NULL;
            }
            int mid =(start+end)/2;
            TreeNode* temp = new TreeNode(mergeArray[mid]);
            temp->left = normalToBalanced(start,mid-1,mergeArray);
            temp->right = normalToBalanced(mid+1,end,mergeArray);
            return temp;
      }

      TreeNode* mergeBSt(TreeNode* root1 ,TreeNode* root2){
            // step 1 : Creating inorder vector and merging them 
            vector<int> bst1,bst2;
            inorder(root1,bst1);
            inorder(root2,bst2);
            //merging 
            vector<int> mergedArray = mergeArr(bst1,bst2);

            //step 2 : 
            int start = 0;
            int end = mergedArray.size()-1;

            return normalToBalanced(start,end,mergedArray);

      }
};
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool foundNull = false;
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front  == nullptr){ 
                // mark true if null node found
                foundNull = true;
            } else {
                // if any non null node found after getting null node
                if(foundNull){
                    return false;
                }
                q.push(front -> left);
                q.push(front -> right);
            }
        }

        return true;
        
    }
};
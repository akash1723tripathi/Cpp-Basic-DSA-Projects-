class Solution {
private:
    void inorderTraversal(TreeNode* root, vector<int> &ans){
      if(root == NULL) return ;

      inorderTraversal(root->left,ans);
      ans.push_back(root->val);
      inorderTraversal(root->right, ans);
    }

    TreeNode* normalToBalanced(int start, int end, vector<int> &ans){
        if(start>end){
            return NULL;
        }
        int mid =(start+end)/2;
        TreeNode* temp = new TreeNode(ans[mid]);
        temp->left = normalToBalanced(start,mid-1,ans);
        temp->right = normalToBalanced(mid+1,end,ans);
        return temp;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ans;
        inorderTraversal(root,ans);
        
        return normalToBalanced(0,ans.size()-1,ans);
    }
};
int main(){
    
}

/// code with booster class
class Booster {
public:
    // Constructor to enable fast I/O
    Booster() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    // Debugging utility for vectors
    template <typename T>
    void debugVector(const vector<T>& vec) {
        for (const auto& val : vec) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Function to compute mid-point safely (to avoid overflow)
    int safeMid(int start, int end) {
        return start + (end - start) / 2;
    }
};


// Solution Class
class Solution {
private:
    Booster booster; // Booster object for utilities

    // In-order Traversal to fill vector
    void inorderTraversal(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;

        inorderTraversal(root->left, ans);
        ans.push_back(root->val);
        inorderTraversal(root->right, ans);
    }

    // Convert sorted array to balanced BST
    TreeNode* normalToBalanced(int start, int end, vector<int>& ans) {
        if (start > end) {
            return NULL;
        }
        int mid = booster.safeMid(start, end); // Use safe mid-point computation
        TreeNode* temp = new TreeNode(ans[mid]);
        temp->left = normalToBalanced(start, mid - 1, ans);
        temp->right = normalToBalanced(mid + 1, end, ans);
        return temp;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ans;

        // Perform in-order traversal and debug the result
        inorderTraversal(root, ans);
        cout << "In-order Traversal Result: ";
        booster.debugVector(ans);

        // Convert sorted vector to balanced BST
        return normalToBalanced(0, ans.size() - 1, ans);
    }
};

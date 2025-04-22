
// Binary Tree Via Inorder & PreOrder Traversal

//approach-1 : build tree 
class Solution {
      public: 
            TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int n = inorder.size();
            int Idx = 0;
            return helper(preorder, inorder, Idx, 0, n-1);
            }
    
            TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& Idx, int left, int right) {
            if (left > right) return NULL;
            int pivot = left;  // find the root from inorder
            while(inorder[pivot] != preorder[Idx]) pivot++;
        
            Idx++;
            TreeNode* newNode = new TreeNode(inorder[pivot]);
            newNode->left = helper(preorder, inorder, Idx, left, pivot-1);
            newNode->right = helper(preorder, inorder, Idx, pivot+1, right);
            return newNode;
      }
};

// approach-2   //mapping
class Solution {

private:
    int preorderIndex;
    unordered_map<int, int> mapping;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        mapping.clear();
        for (int i = 0; i < inorder.size(); i++) {
            mapping[inorder[i]] = i;
        }

        preorderIndex = 0;
        return build(preorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* build(vector<int>& preorder, int start, int end) {
        if (start > end) return nullptr;

        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = mapping[rootVal];

        root->left = build(preorder, start, mid - 1);
        root->right = build(preorder, mid + 1, end);

        return root;
    }    
};

// Binary Tree Via Inorder & PostOrder Trversal

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> index;
        for (int i = 0; i < inorder.size(); i++) {
            index[inorder[i]] = i;
        }
        return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, index);
    }
    
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inorderStart, int inorderEnd, int postorderStart, int postorderEnd, unordered_map<int, int>& index) {
        if (inorderStart > inorderEnd || postorderStart > postorderEnd) {
            return nullptr;
        }
        int rootVal = postorder[postorderEnd];
        TreeNode* root = new TreeNode(rootVal);
        int inorderRootIndex = index[rootVal];
        int leftSubtreeSize = inorderRootIndex - inorderStart;
        root->left = buildTreeHelper(inorder, postorder, inorderStart, inorderRootIndex - 1, postorderStart, postorderStart + leftSubtreeSize - 1, index);
        root->right = buildTreeHelper(inorder, postorder, inorderRootIndex + 1, inorderEnd, postorderStart + leftSubtreeSize, postorderEnd - 1, index);
        return root;
    }
};


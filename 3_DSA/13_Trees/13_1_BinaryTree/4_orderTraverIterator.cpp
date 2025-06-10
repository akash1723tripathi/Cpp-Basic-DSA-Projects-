#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Definition of TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Iterative Inorder Traversal
void inorderTraversal(TreeNode* root) {
    stack<TreeNode*> st;
    TreeNode* current = root;
    
    cout << "Inorder Traversal: ";
    while (current != nullptr || !st.empty()) {
        while (current != nullptr) {
            st.push(current);
            current = current->left;
        }
        current = st.top();
        st.pop();
        cout << current->val << " ";
        current = current->right;
    }
    cout << endl;
}

// Iterative Preorder Traversal
void preorderTraversal(TreeNode* root) {
    if (!root) return;

    stack<TreeNode*> st;
    st.push(root);

    cout << "Preorder Traversal: ";
    while (!st.empty()) {
        TreeNode* current = st.top();
        st.pop();
        cout << current->val << " ";

        if (current->right) st.push(current->right);
        if (current->left) st.push(current->left);
    }
    cout << endl;
}

// Iterative Postorder Traversal
void postorderTraversal(TreeNode* root) {
    if (!root) return;

    stack<TreeNode*> st1, st2;
    st1.push(root);

    while (!st1.empty()) {
        TreeNode* current = st1.top();
        st1.pop();
        st2.push(current);

        if (current->left) st1.push(current->left);
        if (current->right) st1.push(current->right);
    }

    cout << "Postorder Traversal: ";
    while (!st2.empty()) {
        cout << st2.top()->val << " ";
        st2.pop();
    }
    cout << endl;
}

// Helper function to create a binary tree
TreeNode* createTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    TreeNode* root = createTree();

    inorderTraversal(root);
    preorderTraversal(root);
    postorderTraversal(root);

    return 0;
}

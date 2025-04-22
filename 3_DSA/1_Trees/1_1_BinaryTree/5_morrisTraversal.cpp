#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> morrisInorderTraversal(TreeNode* root) {
    vector<int> result;
    TreeNode* current = root;

    while (current) {
        if (!current->left) {
            // If there is no left child, visit the current node and move to the right child
            result.push_back(current->val);
            current = current->right;
        } else {
            // Find the predecessor (rightmost node in the left subtree)
            TreeNode* predecessor = current->left;
            while (predecessor->right && predecessor->right != current) {
                predecessor = predecessor->right;
            }

            if (!predecessor->right) {
                // Make a temporary link from the predecessor to the current node
                predecessor->right = current;
                current = current->left;
            } else {
                // Revert the changes (break the temporary link)
                predecessor->right = nullptr;
                result.push_back(current->val);
                current = current->right;
            }
        }
    }

    return result;
}

// Helper function to create a sample tree
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}

// Main function
int main() {
    TreeNode* root = createSampleTree();
    vector<int> inorderTraversal = morrisInorderTraversal(root);

    cout << "Morris In-order Traversal: ";
    for (int val : inorderTraversal) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
 
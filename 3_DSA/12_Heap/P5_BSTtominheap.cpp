#include <iostream>
#include <vector>

using namespace std;

// Function to perform an inorder traversal and store elements in a vector
void inorderTraversal(Node* root, vector<int>& inorder) {
    if (!root) return;

    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}

// Function to replace the BST nodes to form a Min Heap using preorder traversal
void convertToMinHeap(Node* root, vector<int>& inorder, int& index) {
    if (!root) return;

    root->data = inorder[index++];
    convertToMinHeap(root->left, inorder, index);
    convertToMinHeap(root->right, inorder, index);
}

// Function to convert BST to Min Heap
void bstToMinHeap(Node* root) {
    vector<int> inorder;
    inorderTraversal(root, inorder); // Get sorted elements of BST

    int index = 0;
    convertToMinHeap(root, inorder, index); // Replace nodes to form Min Heap
}

// Function to print the preorder traversal of the tree
void preorderTraversal(Node* root) {
    if (!root) return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Example usage
int main() {
    cout << "Preorder traversal of the original BST:\n";
    preorderTraversal(root);
    cout << endl;

    // Convert BST to Min Heap
    bstToMinHeap(root);

    cout << "Preorder traversal of the Min Heap:\n";
    preorderTraversal(root);
    cout << endl;

    return 0;
}

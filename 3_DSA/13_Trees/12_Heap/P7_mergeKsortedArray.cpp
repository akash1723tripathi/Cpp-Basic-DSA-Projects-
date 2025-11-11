// GFG 

#include <queue>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    int i; // Row index
    int j; // Column index
    
    // Constructor
    Node(int data, int row, int col) {
        this->data = data;
        this->i = row;
        this->j = col;
    }
};

class Compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data; // Min-heap based on data value
    }
};

class Solution {
public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>>& arr, int K) {
        priority_queue<Node*, vector<Node*>, Compare> minHeap;

        // Step 1: Insert the first element of each array into the min-heap
        for (int i = 0; i < K; i++) {
            if (!arr[i].empty()) {
                Node* temp = new Node(arr[i][0], i, 0);
                minHeap.push(temp);
            }
        }

        vector<int> ans;

        // Step 2: Process the min-heap
        while (!minHeap.empty()) {
            Node* temp = minHeap.top();
            ans.push_back(temp->data);
            minHeap.pop();

            int i = temp->i;
            int j = temp->j;

            // If the next element in the same row exists, push it to the heap
            if (j + 1 < arr[i].size()) {
                Node* next = new Node(arr[i][j + 1], i, j + 1);
                minHeap.push(next);
            }
        }
        return ans;
    }
};
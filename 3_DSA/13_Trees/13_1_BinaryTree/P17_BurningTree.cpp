//approach -1 babbar 
class Solution {
public:
    // Create a mapping from nodes to their parents and locate the target node.
    TreeNode* createParentMapping(TreeNode* root, int start, unordered_map<TreeNode*, TreeNode*>& nodeToParent) {
        TreeNode* targetNode = nullptr;
        queue<TreeNode*> q;
        q.push(root);
        nodeToParent[root] = nullptr;

        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if (front->val == start) {
                targetNode = front;
            }
            if (front->left) {
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            if (front->right) {
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return targetNode;
    }

    // Burn the tree starting from the target node and calculate the time.
    int burnTree(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& nodeToParent) {
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(root);
        visited[root] = true;

        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool flag = false;

            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();

                // Visit left child
                if (front->left && !visited[front->left]) {
                    flag = true;
                    q.push(front->left);
                    visited[front->left] = true;
                }

                // Visit right child
                if (front->right && !visited[front->right]) {
                    flag = true;
                    q.push(front->right);
                    visited[front->right] = true;
                }

                // Visit parent
                if (nodeToParent[front] && !visited[nodeToParent[front]]) {
                    flag = true;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = true;
                }
            }

            if (flag) {
                time++;
            }
        }
        return time;
    }

    // Main function to calculate the amount of time to burn the tree.
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> nodeToParent;
        TreeNode* targetNode = createParentMapping(root, start, nodeToParent);
        return burnTree(targetNode, nodeToParent);
    }
};


//appraoch 2
class Solution {
private: 
    pair<bool, int> dfs(TreeNode *node, int val, int &res) {
        if (!node) return {false, 0}; 

        auto [foundLeft, depthLeft] = dfs(node->left, val, res); 
        auto [foundRight, depthRight] = dfs(node->right, val, res); 
        int cur = max(depthLeft, depthRight); 

        if (node->val == val) {
            res = max(res, cur); 
            return {true, 0}; 
        }

        if (foundLeft || foundRight) {
            int cur = depthLeft + depthRight + 1; 
            res = max(res, cur); 
            return {true, (foundLeft ? depthLeft : depthRight) + 1}; 
        }

        res = max(res, cur); 
        return {false, cur + 1}; 
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        int res = 0; 
        dfs(root, start, res);  
        return res; 
    }
};
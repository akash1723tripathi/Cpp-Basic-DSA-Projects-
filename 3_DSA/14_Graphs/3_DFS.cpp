#include <iostream>
#include <vector>

using namespace std;


void dfsWithStack(int startNode, vector<bool> &visited, const vector<vector<int>> &adj, vector<int> &component) {
    stack<int> st;
    
    // 1. Initialize the stack with the starting node
    st.push(startNode);

    while (!st.empty()) {
        // 2. Get the top node from the stack
        int currNode = st.top();
        st.pop();

        // 3. Since nodes can be pushed to the stack multiple times from different neighbors,
        // we only process them if they haven't been visited yet.
        if (!visited[currNode]) {
            visited[currNode] = true;
            component.push_back(currNode);

            // 4. Push all unvisited neighbors onto the stack.
            // (Optional: Traversing in reverse order keeps the traversal order identical to recursive DFS)
            for (auto it = adj[currNode].rbegin(); it != adj[currNode].rend(); ++it) {
                int neighbor = *it;
                if (!visited[neighbor]) {
                    st.push(neighbor);
                }
            }
        }
    }
}

void dfs(int node, vector<bool> &visited, const vector<vector<int>> &adj, vector<int> &component) {
    // 1. Immediately record the current node and flag it as processed
    component.push_back(node);
    visited[node] = true;

    // 2. Explore all neighbors of the current vertex sequentially
    for (const int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            // Dive deeper along the current path recursively
            dfs(neighbor, visited, adj, component);
        }
    }            
}

vector<vector<int>> depthFirstSearch(int V, int E, const vector<vector<int>> &edges) {
    // Fast I/O optimization loop (highly recommended for platform submissions)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 1. Structure the Adjacency List using pre-allocated contiguous vectors.
    // This provides O(1) random-access lookups and excellent CPU cache locality.
    vector<vector<int>> adj(V);
    for (size_t i = 0; i < edges.size(); ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u); // Bidirectional insertion defines an undirected graph
    }

    vector<vector<int>> ans;
    
    // 2. Space-optimized boolean tracker.
    // Behind the scenes, std::vector<bool> packs flags into individual bits instead of bytes.
    vector<bool> visited(V, false);

    // 3. Main loop ensuring disconnected sub-graphs are thoroughly discovered
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            vector<int> component;
            
            // Initiate traversal for a brand-new connected component
            dfs(i, visited, adj, component);
            
            // Store the fully extracted component group
            ans.push_back(component);
        }
    }
    
    return ans;
}
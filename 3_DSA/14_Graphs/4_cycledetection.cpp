// using BFS
#include <queue>
#include <unordered_map>
#include <list>
#include <vector>

using namespace std;

bool isCyclicBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj) {
    unordered_map<int, int> parent;
    queue<int> q;

    parent[src] = -1;
    visited[src] = true;
    q.push(src);

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (auto ngh : adj[front]) {
            if (visited[ngh] && ngh != parent[front]) {
                return true;
            } else if (!visited[ngh]) {
                q.push(ngh);
                visited[ngh] = true;
                parent[ngh] = front;
            }
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m) {
    // Creating adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        // Handling 1-based indexing
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    // Handling disconnected components
    for (int i = 1; i <= n; i++) { // If 1-based indexing, loop from 1 to n
        if (!visited[i]) { // Ensure node exists in adj list
            bool ans = isCyclicBFS(i, visited, adj);
            if (ans==true) {
                return "Yes";
            }
        }
    }
    return "No";
}



//using DFS
#include <unordered_map>
#include <list>
#include <vector>

bool  isCyclicDFS(int node, int parent, unordered_map<int,bool> &visited, unordered_map<int,list<int> &adj){
    visited[node]=true;
    for(auto ngh:adj[node]){
        if(!visited[ngh]){
            bool cycleDetected =  isCyclicDFS(ngh,node,visited,adj);
            if(cycleDetected){
                return true;
            }
        }
        else if(ngh != parent){
            return true;
        }
    }
    return false; 
}

string cycleDetection(vector<vector<int>> &edges, int n, int m) {
    // Creating adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        // Handling 1-based indexing
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    // Handling disconnected components
    for (int i = 1; i <= n; i++) { // If 1-based indexing, loop from 1 to n
        if (!visited[i]) { // Ensure node exists in adj list
            bool ans = isCyclicDFS(i,-1, visited, adj);
            if (ans==true) {
                return "Yes";
            }
        }
    }
    return "No";
}
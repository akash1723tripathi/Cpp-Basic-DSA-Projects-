// using DFS 

#include<list>
#include<unordered_map>
#include<vector>


bool checkForCycleDFS(int node, unordered_map<int,bool> &visited, unordered_map<int,bool> &dfsVisited, unordered_map<int,list<int>> &adj){
  visited[node]=true;
  dfsVisited[node]=true;

  for(auto ngh:adj[node]){
    if(!visited[ngh]){
      bool cycleDetect = checkForCycleDFS(ngh,visited,dfsVisited,adj);
        if(cycleDetect){
          return true;
        }
    }
    else if(dfsVisited[ngh]){
        return true;
    }
  }
  dfsVisited[node]=false;
  return false;
}


int detectCycleInDirectedGraph(int n, vector<pair< int, int >> & edges) {
    unordered_map<int,list<int>> adj;
     for(int i=0;i<edges.size();i++){
       int u = edges[i].first;
       int v = edges[i].second; 

       adj[u].push_back(v);
    }  

    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsVisited;

    for(int i=1;i<=n;i++){
      if(!visited[i]){
        bool cycleFound = checkForCycleDFS(i,visited,dfsVisited,adj);
        if(cycleFound){
          return true;
        }
      }           
    }
    return false;
}






//using BFS - kahn`s algo 

#include <vector>
#include <queue>

using namespace std;

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
    // Creating adjacency list
    vector<vector<int>> adj(n);
    for (auto &edge : edges) {
        int u = edge.first - 1;
        int v = edge.second - 1;
        adj[u].push_back(v);
    }

    // Calculating indegree
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++) {
        for (int neighbor : adj[i]) {
            indegree[neighbor]++;
        }
    }

    // Push nodes with 0 indegree into the queue
    queue<int> q;
    for (int i = 0; i < n; i++) {  // FIX: Start from 0 instead of 1
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // Perform BFS (Kahn's Algorithm)
    int processedNodes = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        processedNodes++;

        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    // If all nodes are processed, no cycle exists
    return (processedNodes != n);
}


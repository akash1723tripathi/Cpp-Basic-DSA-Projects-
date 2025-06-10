// Tarjan`s ALgo

#include <unordered_map>
#include <list>
#include <vector>
#include <iostream>
using namespace std;

void dfs(int node, int parent, int &timer, unordered_map<int, list<int>> &adj,
         unordered_map<int, bool> &visited, vector<int> &disc, vector<int> &low,
         vector<vector<int>> &result)
{ // Pass result by reference
      visited[node] = true;
      disc[node] = low[node] = timer++;

      for (auto ngh : adj[node])
      {
            if (ngh == parent)
            {
                  continue;
            }
            if (!visited[ngh])
            {
                  dfs(ngh, node, timer, adj, visited, disc, low, result);
                  low[node] = min(low[node], low[ngh]);

                  // Check for a bridge
                  if (low[ngh] > disc[node])
                  {
                        result.push_back({node, ngh});
                  }
            }
            else
            {
                  // Back edge case
                  low[node] = min(low[node], disc[ngh]);
            }
      }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
      unordered_map<int, list<int>> adj;

      // Construct adjacency list
      for (int i = 0; i < edges.size(); i++)
      {
            int u = edges[i][0];
            int v = edges[i][1];

            // Undirected graph
            adj[u].push_back(v);
            adj[v].push_back(u);
      }

      int timer = 0;
      vector<int> disc(v, -1);
      vector<int> low(v, -1);
      unordered_map<int, bool> visited;
      vector<vector<int>> result;

      // Run DFS for all components
      for (int i = 0; i < v; i++)
      {
            if (!visited[i])
            {
                  dfs(i, -1, timer, adj, visited, disc, low, result);
            }
      }

      return result;
}
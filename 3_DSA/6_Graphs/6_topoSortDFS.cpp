#include <bits/stdc++.h>
#include <unordered_map>
#include <list>
#include <stack>
#include <vector>

void topoSort(int node, vector<bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj)
{
      visited[node] = true;

      for (auto ngh : adj[node])
      {
            if (!visited[ngh])
            {
                  topoSort(ngh, visited, s, adj);
            }
      }

      // pushing element every time we return from call
      s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
      unordered_map<int, list<int>> adj;
      vector<bool> visited(v, false); // unordered_map<int,bool> visited is not used to improve the runtime complexity
      stack<int> s;

      // for adj
      for (int i = 0; i < e; i++)
      {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
      }

      // for every vertices of the graph
      for (int i = 0; i < v; i++)
      {
            if (!visited[i])
            {
                  topoSort(i, visited, s, adj);
            }
      }

      vector<int> ans;
      while (!s.empty())
      {
            ans.push_back(s.top());
            s.pop();
      }
      return ans;
}
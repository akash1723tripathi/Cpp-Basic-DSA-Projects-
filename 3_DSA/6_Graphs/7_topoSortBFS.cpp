// kahn`s Algo

#include <iostream>
#include <vector>
#include <queue>

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes)
{
      // Creating adjacency list
      vector<vector<int>> adj(nodes);
      for (int i = 0; i < edges; i++)
      {
            int u = graph[i][0];
            int v = graph[i][1];
            adj[u].push_back(v);
      }

      // Calculating indegree
      vector<int> indegree(nodes, 0);
      for (int i = 0; i < nodes; i++)
      {
            for (auto j : adj[i])
            {
                  indegree[j]++;
            }
      }

      // Push nodes with 0 indegree into the queue
      queue<int> q;
      for (int i = 0; i < nodes; i++)
      {
            if (indegree[i] == 0)
            {
                  q.push(i);
            }
      }

      // Perform BFS (Kahn's Algorithm)
      vector<int> ans;
      while (!q.empty())
      {
            int front = q.front();
            q.pop();
            ans.push_back(front);

            for (auto ngh : adj[front])
            {
                  indegree[ngh]--;
                  if (indegree[ngh] == 0)
                  {
                        q.push(ngh);
                  }
            }
      }
      return ans;
}

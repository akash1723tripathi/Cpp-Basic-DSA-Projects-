#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

void findArticulationPoints(int node, int parent, int &timer, unordered_map<int, list<int>> &adj,
                            vector<int> &disc, vector<int> &low, vector<bool> &visited,
                            vector<bool> &isArticulation, int &children)
{
      visited[node] = true;
      disc[node] = low[node] = timer++;

      for (auto ngh : adj[node])
      {
            if (ngh == parent)
                  continue;

            if (!visited[ngh])
            {
                  children++;
                  findArticulationPoints(ngh, node, timer, adj, disc, low, visited, isArticulation, children);

                  low[node] = min(low[node], low[ngh]);

                  if (parent != -1 && low[ngh] >= disc[node])
                        isArticulation[node] = true;
            }
            else
            {
                  low[node] = min(low[node], disc[ngh]);
            }
      }

      if (parent == -1 && children > 1)
            isArticulation[node] = true;
}

vector<int> getArticulationPoints(int n, vector<vector<int>> &edges)
{
      unordered_map<int, list<int>> adj;
      for (auto &edge : edges)
      {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
      }

      vector<int> disc(n, -1), low(n, -1);
      vector<bool> visited(n, false), isArticulation(n, false);
      int timer = 0;

      for (int i = 0; i < n; i++)
      {
            if (!visited[i])
            {
                  int children = 0;
                  findArticulationPoints(i, -1, timer, adj, disc, low, visited, isArticulation, children);
            }
      }

      vector<int> articulationPoints;
      for (int i = 0; i < n; i++)
      {
            if (isArticulation[i])
                  articulationPoints.push_back(i);
      }
      return articulationPoints;
}

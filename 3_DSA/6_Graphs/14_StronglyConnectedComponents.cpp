// strongly connected compomnents using TARJAN`S algo 


#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <list>
using namespace std;

void tarjanDFS(int node, int &timer, unordered_map<int, list<int>> &adj,
               vector<int> &disc, vector<int> &low, stack<int> &st,
               vector<bool> &onStack, vector<vector<int>> &sccs)
{
      disc[node] = low[node] = timer++;
      st.push(node);
      onStack[node] = true;

      for (auto ngh : adj[node])
      {
            if (disc[ngh] == -1)
            {
                  tarjanDFS(ngh, timer, adj, disc, low, st, onStack, sccs);
                  low[node] = min(low[node], low[ngh]);
            }
            else if (onStack[ngh])
            {
                  low[node] = min(low[node], disc[ngh]);
            }
      }

      if (low[node] == disc[node])
      {
            vector<int> scc;
            while (!st.empty())
            {
                  int top = st.top();
                  st.pop();
                  onStack[top] = false;
                  scc.push_back(top);
                  if (top == node)
                        break;
            }
            sccs.push_back(scc);
      }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
      unordered_map<int, list<int>> adj;
      for (auto &edge : edges)
      {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
      }

      vector<int> disc(n, -1), low(n, -1);
      stack<int> st;
      vector<bool> onStack(n, false);
      vector<vector<int>> sccs;
      int timer = 0;

      for (int i = 0; i < n; i++)
      {
            if (disc[i] == -1)
            {
                  tarjanDFS(i, timer, adj, disc, low, st, onStack, sccs);
            }
      }

      return sccs;
}

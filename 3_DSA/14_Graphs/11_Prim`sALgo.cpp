#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
#include <list>
#include <limits> 


ve ctor<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Creating adjacency list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Initialize required vectors
    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    // Start from node 1
    key[1] = 0;

    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX, u = -1;

        // Finding the minimum key value node that is not in MST
        for (int v = 1; v <= n; v++)
        {
            if (!mst[v] && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }

        // If no valid node is found, break early (handles disconnected graphs)
        if (u == -1)
            break;

        // Mark the node as included in MST
        mst[u] = true;

        // Update adjacent nodes
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (!mst[v] && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    // Constructing the MST result
    vector<pair<pair<int, int>, int>> res;
    for (int i = 2; i <= n; i++)
    {
        if (parent[i] != -1) // Ensure valid edges are added
            res.push_back({{parent[i], i}, key[i]});
    }

    return res;
}


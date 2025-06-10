//using set 

#include <bits/stdc++.h>
#include <unordered_map>
#include <set>
#include <vector>
#include <list>    
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    //creating adj list
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<edges ;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    // creating dist vector 
    vector<int> dist(vertices);
    for(int i=0;i<vertices;i ++){
        dist[i]=INT_MAX; 
    }

    set<pair<int,int>> st;

    dist[source]=0;
    st.insert(make_pair(0,source));

    while(!st.empty()){

        // detching the top node
        auto top = *(st.begin());

        //marking the feteched node
        int NodeDistance = top.first;
        int topNode = top.second;

        //remove the top record
        st.erase(st.begin());

        //traverse on ngh
        for(auto ngh: adj[topNode]){
            if(NodeDistance+ ngh.second < dist[ngh.first]){

                auto record = st.find(make_pair(dist[ngh.first],ngh.first));
                //if record found , then earse it 
                if(record != st.end()){
                    st.erase(record);
                }

                //distance update
                dist[ngh.first] = NodeDistance + ngh.second ;

                // record push in set 
                st.insert(make_pair(dist[ngh.first],ngh.first));
            }
        }
    }
    return dist;
}


//using priority queue 

#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
#include <queue>
#include <list>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Creating adjacency list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Distance vector initialized to infinity
    vector<int> dist(vertices, INT_MAX);
    
    // Min-heap (priority queue), stores pairs {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Initialize source distance and push to priority queue
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int NodeDistance = pq.top().first;
        int topNode = pq.top().second;
        pq.pop();

        // Traverse all neighbors
        for (auto &ngh : adj[topNode]) {
            int nextNode = ngh.first;
            int edgeWeight = ngh.second;
            
            if (NodeDistance + edgeWeight < dist[nextNode]) {
                dist[nextNode] = NodeDistance + edgeWeight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }
    return dist;
}
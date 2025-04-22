// krushkal algo to find MST
// disjoint data structure
// input format edges --> (0,1,2) 

#include<algorithm>

bool cmp(vector<int> &a, vector<int> &b){
  return a[2]<b[2];
}

void makeSet(vector<int> &parent, vector<int> &rank, int n){
  for(int i=0;i<n;i++){
    parent[i]=i;
    rank[i]=0;
  }
}

int findparent(vector<int>  &parent, int node){
  if(parent[node]==node){
      return node;
  }
  //logic for path compression
  return parent[node]=findparent(parent,parent[node]);
}

void unionSet(vector<int> &parent, vector<int> &rank, int u, int v){
  u= findparent(parent,u);
  v= findparent(parent,v);

  if(rank[u]<rank[v]){
    parent[u]=v;
  }
  else if(rank[v]<rank[u]){
    parent[v]=u;
  }
  else{
    parent[v]=u;
    rank[u]++;
  }
}


int kruskalMST(int n, vector<vector<int>> &edges)
{
  sort(edges.begin(),edges.end(),cmp);
  vector<int> parent(n);
  vector<int> rank(n);
  makeSet(parent, rank, n );

  int minWeight = 0;
  for(int i =0;i<edges.size();i++){
    int u = findparent(parent,edges[i][0]);
    int v = findparent(parent,edges[i][1]);
    int wt = edges[i][2];

    if(u!=v){
      minWeight += wt;
      unionSet(parent,rank,u,v);
    }
  }
  return minWeight;
}
// using adjaency list 

#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template <typename T>

class Graph{

      public:
            unordered_map<T, list<T>> adj_list;

            void addEdge(T u, T v, bool direction ){
                  // direction = 0 -> undirected 
                  // direction = 1 -> directed 

                  //create an edge from u and v 
                  adj_list[u].push_back(v);
                  if(direction == 0){
                        adj_list[v].push_back(u);
                  }
            }

            void printAdjList(){
                  for
                  (auto i: adj_list){
                        cout<< i.first <<"->";
                        for(auto j: i.second){
                              cout<<j<<",";
                        }
                        cout<<endl;
                  }
            }
};

int main(){

      int n,m;
      cout<<"Enter the number of Nodes : ";
      cin>>n;
      cout<<"Enter the number of edges : ";
      cin>>m; 

      Graph<int> g;

      cout<<endl<<"Enter pair set of edge : ";
      for(int i=0;i<m;i++){
            int u,v,direction;
            cin>>u>>v;
            cout<<endl<<"direction ? ";
            cin>>direction;
            //creating an directed graph
            g.addEdge(u,v,direction);
      }

      g.printAdjList();
      
      return 0;
}
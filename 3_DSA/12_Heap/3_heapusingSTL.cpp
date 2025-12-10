#include<iostream>
#include<queue>
using namespace std;

int main(){
      cout<<"using priority queue"<<endl;
      // defauly max heap
      priority_queue<int> maxheap;                       

      maxheap.push(5);
      maxheap.push(8);
      maxheap.push(12);
      maxheap.push(2);
      maxheap.push(4);

      cout<<"maxheap top : "<<maxheap.top()<<endl;
      maxheap.pop();
      cout<<"maxheap top : "<<maxheap.top()<<endl;
      cout<<"maxheap size : "<<maxheap.size()<<endl;


      // min heap
      priority_queue<int, vector<int>, greater<int>> minheap;                       

      minheap.push(5);
      minheap.push(8);
      minheap.push(12);
      minheap.push(2);
      minheap.push(4);

      cout<<"minheap top : "<<minheap.top()<<endl;
      minheap.pop();
      cout<<"minheap top : "<<minheap.top()<<endl;
      cout<<"minheap size : "<<minheap.size()<<endl;

}
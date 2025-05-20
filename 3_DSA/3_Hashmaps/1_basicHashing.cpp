#include<iostream>
using namespace std;

int main(){
      int n;
      cin>>n;
      int arr[n];
      for(int i=1;i<n;i++){
            cin>>arr[i];
      }

      //precompute
      int hasharr[n+1]={0};
      for(int i=0;i<n;i++){
            hasharr[arr[i]] +=1;
      }

      //test case 
      int q;
      cin>>q;
      while(q--){
            int num;
            cin >> num;
            //fetch
            cout<<hasharr[num]<<endl;
      }

}

//test case
// 5 
// 1 3 2 1 3
// 5 
// 1
// 4
// 2
// 3
// 12
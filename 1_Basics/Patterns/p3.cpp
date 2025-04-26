// 1 2 3 
// 4 5 6 
// 7 8 9

#include <iostream>
using namespace std;

int main(){
      int count = 1;
      for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                  cout<<count<<" ";
                  count++;
            }
            cout<<endl;
      }

      cout<<"naya pattern hai "<<endl;
      
      int count2 = 9;
      for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                  cout<<count2<<" ";
                  count2--;
            }
            cout<<endl;
      }
}
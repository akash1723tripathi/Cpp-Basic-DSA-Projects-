// *
// * *
// * * *
// * * * *
// * * * * *
// * * * *
// * * *
// * *
// *

#include<iostream>
using namespace std;

int main(){
      for(int i=0;i<=2*5-1;i++){
            int star = i;
            if(i > 5) star = 2*5-i; 
            for(int j=0;j <star;j++){
                  cout<<"*"<<" ";
            }
            cout<<endl;
      }
}
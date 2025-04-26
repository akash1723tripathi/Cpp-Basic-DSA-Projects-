// *                 * 
// * *             * *    
// * * *         * * *
// * * * *     * * * *
// * * * * * * * * * *
// * * * *     * * * *
// * * *         * * *
// * *             * *
// *                 *

#include<iostream>
using namespace std;

int main(){
      int n;
      cin>>n;
      int spaces = 2*n-2;
      for(int i=0;i<=2*n-1;i++){
            int star = i;
            if(i > 5) star = 2*n-i; 
            //star
            for(int j=0; j<star;j++){
                  cout<<"*";
            }
            //space
            for(int j=0;j<spaces;j++){
                  cout<<" ";
            }
            //star
            for(int j=0; j<star;j++){
                  cout<<"*";
            }
            cout<<endl;
            if(i<n) spaces -=2;
            else spaces +=2;
      }
}
#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

int main(){
      //first method
      int n;
      cout<<"enter the number : ";
      cin>>n;
      int r,count=0;
      while(n>0){
            r=n/10;
            count++;
            n=n/10;
      }
      cout<<"No of digits = "<<count;

      //second method
      int cnt = (int)(log10(n)+1)
}

// count digits : TC : O(log10(n))
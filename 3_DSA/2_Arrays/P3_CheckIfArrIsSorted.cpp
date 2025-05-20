#include<iostream>
#include<vector>

int isSorted(int n, vector<int> &arr){
      for(int i=0;i<n;i++){
            if(arr[i]<arr[i+1]){
            }
            else{
                  return false;
            }
      }
      return true;
}
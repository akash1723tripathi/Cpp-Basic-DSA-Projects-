//aprroach 1- Brute Force 
#include<algorithm>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      vector<int> sumstore;
      int n=nums.size();
      for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=1;j<n;j++){
                  sum += arr[j];
                  sumstore.push_back(sum);
            }
      }

      sort( sumstore.begin() , sumstore.end() );
      return sumstore[sumstore.size()-k];  
    }       
};


// appraoch 2 - min heap 
#include<queue>
int getkthLargest(vector<int> &arr, int k){
      priority_queue<int,vector<int>,greater<int> mini;
      int n=arr.size();
      for(int i=0;i<n;i++){
            int sum=0;
            for(j=i;j<n;j++){
                  sum = +arr[j];
                  if(mini.size() < k){
                        mini.push(sum);
                  }
                  else{
                        if(sum>mini.top()){
                              mini.pop();
                              mini.push(sum);
                        }
                  }
            }
      }
      return mini.top();

}
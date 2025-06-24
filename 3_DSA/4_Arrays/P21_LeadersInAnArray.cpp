#include <bits/stdc++.h> 
vector<int> findLeaders(vector<int> &elements, int n) {
      vector<int> ans;
      int maxi = elements[n-1];
      ans.push_back(elements[n-1]);

      for(int i=n-2;i>=0;i--){
            if(elements[i]>maxi){
                  ans.push_back(elements[i]);
            }
            maxi = max(maxi,elements[i]);
      }
      reverse(ans.begin(),ans.end());
      return ans;
   
}

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
      if(n==0) return 0;
      int longest =1;
      unordered_set<int> st;
      // inserting all elements 
      for(int i=0;i<n;i++)
      {
            st.insert(arr[i]);
      }

      //trasversing over the set 
      for(auto i : st){
            //chack for previous 
            if(st.find(i-1) == st.end()){
                  int cnt =1;
                  int x = i;
                  while(st.find(x+1) != st.end()){
                  x++;
                  cnt++;
                  } 
                  longest = max(longest,cnt);
            }
      }
      return longest;
}
//via balance variable 
class Solution {
public:
      int maxDepth(string s) {
            int bal = 0,ans=0;
            for(char c:s){
                  if(c=='('){ 
                        bal++;
                        ans=max(ans,bal);
                  }
                  else if(c==')'){
                        bal--;
                  }else{
                        continue;
                  }
            }
      return ans;
      }
};
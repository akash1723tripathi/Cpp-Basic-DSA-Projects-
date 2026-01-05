//Brute
class Solution {
   public:
      int celebrity(vector<vector<int>>& mat) {
            int n = mat.size();
            vector<int> km(n,0);
            vector<int> ik(n,0);
            
            for(int i=0;i<n;i++){
                  for(int j=0;j<n;j++){
                  if(mat[i][j]==1){
                        km[j]++;
                        ik[i]++;
                  }
                  }
            }
            
            for(int i=0;i<n;i++){
                  if( km[i]==n-1 && ik[i]==0){
                  return i;
                  }
            }
            
            return 0;
       
      }
};
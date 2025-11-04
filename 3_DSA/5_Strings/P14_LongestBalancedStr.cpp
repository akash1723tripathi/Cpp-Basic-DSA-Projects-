class Solution {
private:
      int getComFreq(vector<int>& freq){
            int comFreq = 0;

            for(int count : freq){
                  if(count>0){
                  if(comFreq == 0){
                        comFreq = count;
                  }else if(count != comFreq){
                        return -1;
                  }
                  }
            }
            return comFreq;
      }
public:
      int longestBalanced(string s) {
            int n = s.length();
            if(n<1) return 0;

            int maxLength = 0;

            for(int i=0;i<n;i++){
                  vector<int> freq(26,0);
                  for(int j=i;j<n;j++){
                  freq[s[j]-'a']++;

                  if(getComFreq(freq)>0){
                        maxLength = max(maxLength,j-i+1);
                  }
                  }
            }
      return maxLength;
      }
};
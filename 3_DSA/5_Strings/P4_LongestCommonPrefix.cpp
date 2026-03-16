// vertical scanning 

class Solution {
public:
      string longestCommonPrefix(vector<string>& strs) {
            string ans ="";
            int n = strs.size();
            //for the first string
            for(int i=0; i<strs[0].length();i++){
                  char ch = strs[0][i];

                  bool match = true;

                  //for comaprision ch with every other string
                  for(int j=1;j<n;j++){
                        if(strs[j].size()<i || ch!=strs[j][i]){
                              match=false;
                              break;
                        }
                  }

                  if(match == false){
                        break;
                  }else{
                        ans.push_back(ch);
                  }
            }
      return ans;
      }
};


//horizontal scanning -- Pehle string ko prefix maan lo, Har agla string aate hi, prefix ko uske saath shrink karte jao.
// Har agla string aate hi, prefix ko uske saath shrink karte jao.

string longestCommonPrefix(vector<string>& strs) {
      string prefix = strs[0];
      for(int i=1; i<strs.size(); i++){
            while(strs[i].find(prefix) != 0){ // prefix not at start
                  prefix.pop_back(); // shrink
                  if(prefix.empty()) return "";
            }
      }
      return prefix;
}


//Sorting + First & Last String


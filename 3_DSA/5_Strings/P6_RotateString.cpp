//Rotate String 
class Solution {
public:
      bool rotateString(string s, string goal) {
            if (s.length() != goal.length()) {
                  return false;
            }
            if(s==goal) return true;
            int i=0;
            while(i<s.size()){
                  rotate(s.begin(),s.begin()+1,s.end());
                  if(s==goal) return true;
                  i++;
            }
      return false;
      }
};

// using string sum method 

class Solution {
public:
      bool rotateString(string s, string goal) {
            if (s.length() != goal.length()) {
                  return false;
            }

            return (s + s).contains(goal);
            return (s + s).find(goal) != string::npos;  
            // string::npos is special type of static const denoting value as in "not found"
            // static const size_t npos = -1; used with find(), substr()

      }
};





// via mannual rotation

if(s.size() != goal.size()) return false;

for(int i = 0; i < s.size(); i++) {
    string rotated = s.substr(i) + s.substr(0, i);
    if(rotated == goal) return true;
}
return false;

class Solution {
public:
      string reverseWords(string s) {
            int n = s.length();
            string ans = "";

            reverse(s.begin(),s.end());

            for(int i=0;i<n;i++){
                  string word = "";
                  while(i<n && s[i] !=' '){
                  word += s[i];
                  i++;
                  }
                  reverse(word.begin(),word.end());
                  
                  if(word.length()>0){
                  ans += " "+ word;
                  }
            }
      return ans.substr(1);
      }
};


// optimized code
class Solution {
public:
      string reverseWords(string &s) {
            int n = s.size();

            // 1. Reverse the whole string
            reverse(s.begin(), s.end());

            int start = 0;
            for (int end = 0; end <= n; end++) {
                  if (end == n || s[end] == ' ') {
                  // reverse each word in-place
                  reverse(s.begin() + start, s.begin() + end);
                  start = end + 1;
                  }
            }

            // 2. Clean up extra spaces in-place
            int i = 0, j = 0;
            while (j < n) {
                  // skip leading spaces
                  while (j < n && s[j] == ' ') j++;
                  // copy word
                  while (j < n && s[j] != ' ') s[i++] = s[j++];
                  // skip spaces between words but leave one
                  while (j < n && s[j] == ' ') j++;
                  if (j < n) s[i++] = ' ';
            }
      s.resize(i); // trim trailing spaces
      return s;
      }
};

// Stack based approach 

class Solution {
public:
      string removeOuterParentheses(string s) {
            int n = s.size();
            stack<char> st;
            string ans = "";
            
            for(int i=0; i<n; i++) {
                  if(st.empty()) {
                  st.push(s[i]);
                  } else {
                  if(st.top() == '(' && s[i] == '(') {
                        st.push(s[i]);
                        ans += s[i];
                  }
                  else if(st.top() == '(' && s[i] == ')') {
                        st.pop();
                        if(!st.empty()) {
                              ans += s[i];
                        }
                  }
                  }
            }
      return ans;
      }
};


// without using stack 

class Solution {
public:
      string removeOuterParentheses(string s) {
            string ans = "";
            int balance = 0;

            for(char c : s) {
                  if(c == '(') {
                  if(balance > 0) ans += c; 
                  balance++;
                  } else {
                  balance--;
                  if(balance > 0) ans += c;
                  }
            }
      return ans;
      }
};

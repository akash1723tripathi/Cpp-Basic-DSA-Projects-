// Naivce Approach 
class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        unordered_map<char,int> used;
        unordered_map<char,int> freq;

        // count frequency
        for(char c : s) freq[c]++;

        for(char x : s) {
            freq[x]--;  // one occurrence used

            // if already used, skip
            if(used[x]) continue;

            // pop only if character appears later again
            while(!st.empty() && st.top() > x && freq[st.top()] > 0) {
                used[st.top()] = 0;
                st.pop();
            }

            st.push(x);
            used[x] = 1;
        }

        // build result
        string result;
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());

        return result;
    }
};








//Optimal 
class Solution {
public:
      string removeDuplicateLetters(string s) {
            vector<int> count(26, 0);
            vector<bool> inStack(26, false);
            stack<char> st;

            for(char c : s) count[c - 'a']++;

            for(char c : s){
                  int idx = c - 'a';
                  count[idx]--;

                  if(inStack[idx]) continue;

                  while(!st.empty() && st.top() > c && count[st.top() - 'a'] > 0){
                  inStack[st.top() - 'a'] = false;
                  st.pop();
                  }

                  st.push(c);
                  inStack[idx] = true;
            }

            string res;
            while(!st.empty()){
                  res += st.top();
                  st.pop();
            }
            reverse(res.begin(), res.end());

            return res;
      }
};
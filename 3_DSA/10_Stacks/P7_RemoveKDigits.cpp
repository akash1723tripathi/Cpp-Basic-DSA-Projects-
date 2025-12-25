//brute force approach
class Solution {
public:
      string removeKdigits(string num, int k) {
            if (k == 0) return strip(num);
            if (num.size() == k) return "0";

            string ans = num;

            for (int i = 0; i < num.size(); i++) {
                  string temp = num.substr(0, i) + num.substr(i + 1);
                  string candidate = removeKdigits(temp, k - 1);

                  if (compare(candidate, ans)) {
                  ans = candidate;
                  }
            }
            return strip(ans);
      }

private:
      // remove leading zeros
      string strip(string s) {
            int i = 0;
            while (i < s.size() && s[i] == '0') i++;
            s = s.substr(i);
            return s.empty() ? "0" : s;
      }

      // compare numeric strings
      bool compare(string a, string b) {
            a = strip(a);
            b = strip(b);

            if (a.size() != b.size())
                  return a.size() < b.size();
            return a < b;
      }
};



//optimal approach

class Solution {
public:
      string removeKdigits(string num, int k) {
            stack<char> st;

            for (char x : num) {
                  while (!st.empty() && st.top() > x && k > 0) {
                  st.pop();
                  k--;
                  }
                  st.push(x);
            }

            // remove remaining digits
            while (k > 0 && !st.empty()) {
                  st.pop();
                  k--;
            }

            // build result
            string result;
            while (!st.empty()) {
                  result.push_back(st.top());
                  st.pop();
            }
            reverse(result.begin(), result.end());

            // remove leading zeros
            int i = 0;
            while (i < result.size() && result[i] == '0') i++;
            result = result.substr(i);

            return result.empty() ? "0" : result;
      }
};



// another optimal approach


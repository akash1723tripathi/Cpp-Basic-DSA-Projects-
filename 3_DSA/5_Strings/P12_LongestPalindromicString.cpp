//Brute Force --o(n^3)

class Solution {
private:
      bool isPalindrome(const string &s, int l, int r) {
            while (l < r) {
                  if (s[l] != s[r]) return false;
                  l++; r--;
            }
            return true;
      }
public:
      string longestPalindrome(string s) {
            int n = s.size();
            if (n == 0) return "";
            int bestL = 0, bestLen = 1;

            for (int i = 0; i < n; ++i) {
                  for (int j = i; j < n; ++j) {
                  int len = j - i + 1;
                  if (len <= bestLen) continue; 
                  if (isPalindrome(s, i, j)) {
                        bestL = i;
                        bestLen = len;
                  }
                  }
            }
            return s.substr(bestL, bestLen);
      }
};



//Expand Around Center
class Solution {
public:
      string longestPalindrome(string s) {
            int n = s.size();
            if (n == 0) return "";

            int start = 0, maxLen = 1;

            // lambda function with capture
            auto expand = [&](int left, int right) {
                  while (left >= 0 && right < n && s[left] == s[right]) {
                  int currLen = right - left + 1;
                  if (currLen > maxLen) {
                        maxLen = currLen;
                        start = left;
                  }
                  left--;
                  right++;
                  }
            };

            for (int i = 0; i < n; i++) {
                  expand(i, i);     // Odd length palindrome
                  expand(i, i + 1); // Even length palindrome
            }

            return s.substr(start, maxLen);
      }
};


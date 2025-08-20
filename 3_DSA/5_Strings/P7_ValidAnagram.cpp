// Brute Force -- via sorting

class Solution {
public:
      bool isAnagram(string s, string t) {
            sort(s.begin(),s.end());
            sort(t.begin(),t.end());
            if(s==t) return true;
            return false;
      }
};



// via frequency Vector

class Solution {
public:
      bool isAnagram(string s, string t) {
            if (s.size() != t.size()) return false;  // length check

            vector<int> freq(26, 0);  // 26 letters for lowercase English chars

            // count frequency
            for (char c : s) {
                  freq[c - 'a']++;
            }
            for (char c : t) {
                  freq[c - 'a']--;
            }

            // check all frequencies should be 0
            for (int count : freq) {
                  if (count != 0) return false;
            }

      return true;
      }
};


// HashMap for more general Solution


class Solution {
public:
      bool isAnagram(string s, string t) {
            if (s.size() != t.size()) return false; // length check

            unordered_map<char, int> freq;

            // count frequencies for s
            for (char c : s) {
                  freq[c]++;
            }

            // decrease frequencies for t
            for (char c : t) {
                  freq[c]--;
                  if (freq[c] < 0) return false;  // extra char in t
            }

            // final check (all should be 0)
            for (auto &entry : freq) {
                  if (entry.second != 0) return false;
            }

      return true;
      }
      };

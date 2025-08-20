
// Hasmap + Set Approach 
class Solution {
public:
      bool isIsomorphic(string s, string t) {
            if(s.size() != t.size()) return false;

            unordered_map<char, char> mapST;
            unordered_set<char> used; // to check if target char already mapped

            for(int i = 0; i < s.size(); i++) {
                  char c1 = s[i];
                  char c2 = t[i];

                  if(mapST.count(c1)) {
                  if(mapST[c1] != c2) return false; // mismatch
                  } else {
                  if(used.count(c2)) return false; // already mapped
                  mapST[c1] = c2;
                  used.insert(c2);
                  }
            }

      return true;
      }
};


//Array Based Approach 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
      bool isIsomorphic(string s, string t) {
            if(s.size() != t.size()) return false;

            vector<int> mapST(256, -1); // s -> t mapping
            vector<int> mapTS(256, -1); // t -> s mapping

            for(int i = 0; i < s.size(); i++) {
                  char c1 = s[i];
                  char c2 = t[i];

                  // If already mapped, check consistency
                  if(mapST[c1] != -1 && mapST[c1] != c2) return false;
                  if(mapTS[c2] != -1 && mapTS[c2] != c1) return false;

                  // Otherwise, create new mapping
                  mapST[c1] = c2;
                  mapTS[c2] = c1;
            }

      return true;
      }
};

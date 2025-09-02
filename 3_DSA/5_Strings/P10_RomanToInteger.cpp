//Roman To Int

class Solution {
public:
      int romanToInt(string s) {
            int res = 0;
            unordered_map<char, int> roman = {
                  {'I', 1},
                  {'V', 5},
                  {'X', 10}, 
                  {'L', 50},
                  {'C', 100},
                  {'D', 500},
                  {'M', 1000}
            };

            for (int i = 0; i < s.size() - 1; i++) {
                  if (roman[s[i]] < roman[s[i + 1]]) { //mapping wali value se comapre karta hu
                  res -= roman[s[i]];
                  } else {
                  res += roman[s[i]];
                  }
            }

            return res + roman[s[s.size() - 1]];  // last element     
       }
};




//Int to Roman

class Solution {
public:
      string intToRoman(int num) {
            vector<pair<int, string>> valueMap = {
                  {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
                  {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
                  {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
            };

            string res = "";
            for (auto &p : valueMap) {
                  while (num >= p.first) {
                  res += p.second;
                  num -= p.first;
                  }
            }
            return res;
      }
};
//via sorting using a comparison function
class Solution {
public:
      string frequencySort(string s) {
            vector<char> freq(128,0);
            for(char ch:s) freq[ch]++;

            auto cmp = [&](char a, char b){
                  if(freq[a]==freq[b]) return a<b;
                  return freq[a]>freq[b];
            };

            sort(s.begin(),s.end(),cmp);
            return s;
      }
};



//Using a hasmap 
class Solution {
public:
      string frequencySort(string s) {
            unordered_map<char,int> freq;
            for(char ch:s) freq[ch]++;

            vector<pair<char,int>> freqArr;
            for(auto [ch,fq]:freq) freqArr.push_back({ch,fq});

            auto cmp = [&](pair<char,int>&a, pair<char,int>&b){
                  return a.second > b.second;
            };
            sort(freqArr.begin(),freqArr.end(),cmp);

            string ans = "";
            for(auto [ch,fq] : freqArr) ans.append(fq,ch);
      return ans; 
      }
};


//more optimized
class Solution {
public:
      string frequencySort(string s) {
            unordered_map<char,int> freq;
            for(char ch:s) freq[ch]++;

            vector<pair<char,int>> freqArr(freq.begin(),freq.end());

            sort(freqArr.begin(),freqArr.end(),[](auto &a,auto &b){
                  return a.second>b.second;
            });

            string ans = "";
            for(auto &p : freqArr){
                  ans.append(p.second,p.first);
            }
            return ans; 
      }
};
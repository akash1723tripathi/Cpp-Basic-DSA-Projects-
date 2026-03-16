class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(auto s:strs){

            //string temp=s;   we can use sorting too
            // sort(temp.begin(),temp.end());
            
            string hashString ="";
            vector<int> freq(26,0);
            for(int i=0;i<s.size();i++) freq[s[i]-'a']++;
            for(int i=0;i<26;i++) {
                hashString.push_back(freq[i]);
                hashString.push_back('#');
            }
            mp[hashString].push_back(s);
        }

        vector<vector<string>> res;
        for(auto [key,vectorOfString] : mp){
            res.push_back(vectorOfString);
        }

        return res;
    }
};
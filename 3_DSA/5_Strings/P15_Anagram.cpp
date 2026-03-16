class Solution
{
public:
      bool isAnagram(string s, string t)
      {
            if (s.length() != t.length())
                  return false;
            vector<int> freq(26, 0);

            for (int i = 0; i < s.size(); i++)
            {
                  freq[s[i] - 'a']++;
            }
            for (int i = 0; i < t.size(); i++)
            {
                  int x = --freq[t[i] - 'a'];
                  if (x < 0)
                        return false;
            }
            return true;
      }
};
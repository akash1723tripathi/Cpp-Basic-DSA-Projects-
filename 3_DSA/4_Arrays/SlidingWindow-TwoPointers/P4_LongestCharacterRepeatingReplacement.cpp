// Brute-->optimal
class Solution
{
public:
      int characterReplacement(string s, int k)
      {
            int n = s.size();
            int maxLen = 0, maxf = 0, l = 0, r = 0, len = 0;
            vector<int> hash(26, 0);
            while (r < n)
            {
                  hash[s[r] - 'A']++;
                  maxf = max(maxf, hash[s[r] - 'A']);

                  while ((r - l + 1) - maxf > 0)
                  {
                        hash[s[l] - 'A']--;
                        for (int i = 0; i < 26; i++)
                        {
                              maxf = max(maxf, hash[i]);
                              l = l + 1;
                        }
                        if ((r + 1 - l) - maxf < k)
                        {
                              maxLen = max(maxLen, r - l + 1);
                        }
                  }
            }
            return maxLen;
      }
};

// Best
class Solution
{
public:
      int characterReplacement(string s, int k)
      {
            int n = s.size();
            vector<int> count(26, 0);
            int l = 0, maxf = 0, maxLen = 0;

            for (int r = 0; r < n; r++)
            {
                  maxf = max(maxf, ++count[s[r] - 'A']);

                  if ((r - l + 1) - maxf > k)
                  {
                        count[s[l] - 'A']--;
                        l++;
                  }

                  maxLen = max(maxLen, r - l + 1);
            }

            return maxLen;
      }
};
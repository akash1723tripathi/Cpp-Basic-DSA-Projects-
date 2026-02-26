class Solution
{
public:
      int longestOnes(vector<int> &nums, int k)
      {
            int n = nums.size();
            int r = 0, l = 0, maxLen = 0, len = 0, z = 0;
            while (r < n)
            {
                  if (nums[r] == 0)
                        z++;
                  if (z > k)
                  {
                        if (nums[l] == 0)
                              z--;
                        l++;
                  }
                  if (z <= k)
                  {
                        len = r + 1 - l;
                        maxLen = max(maxLen, len);
                  }
                  r++;
            }
            return maxLen;
      }
};
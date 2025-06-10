// to return the max len of subarray -- code 360
#include <bits/stdc++.h>
int getLongestSubarray(vector<int> &nums, int k)
{
      map<int, int> preSum;
      int sum = 0, maxLen = 0;

      for (int i = 0; i < nums.size(); i++)
      {
            sum += nums[i];

            if (sum == k)
            {
                  maxLen = max(maxLen, i + 1);
            }

            int rem = sum - k;
            if (preSum.find(rem) != preSum.end())
            {
                  int len = i - preSum[rem];
                  maxLen = max(maxLen, len);
            }

            //to handle cases including zero
            if (preSum.find(sum) == preSum.end())
            {
                  preSum[sum] = i;
            }
      }

      return maxLen;
}

// to return number of subarray with sum k
class Solution
{
public:
      int subarraySum(vector<int> &nums, int k)
      {
            map<int, int> preSum;
            int sum = 0, count = 0;

            preSum[0] = 1; // Important: to handle subarrays starting from index 0

            for (int i = 0; i < nums.size(); i++)
            {
                  sum += nums[i];

                  int rem = sum - k;
                  if (preSum.find(rem) != preSum.end())
                  {
                        count += preSum[rem]; // ✅ Add all ways to get sum-k
                  }

                  preSum[sum]++; // ✅ Increment prefix sum frequency
            }

            return count;
      }
};

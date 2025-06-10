class Solution
{
public:
      int removeDuplicates(vector<int> &nums)
      {
            int n = nums.size();
            if (n <= 1)
                  return n;

            int *i = &nums[0]; // slow pointer (unique values)
            int *j = &nums[1]; // fast pointer (traverse through array)
            int k = 1;         // start from 1 because nums[0] is always unique

            for (int idx = 1; idx < n; idx++)
            {
                  if (*j != *i)
                  {
                        i++;     // move to next position
                        *i = *j; // assign unique value
                        k++;     // increase count of unique elements
                  }
                  j++; // move fast pointer
            }

            return k;
      }
};

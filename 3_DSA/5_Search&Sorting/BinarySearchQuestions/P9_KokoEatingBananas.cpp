class Solution {
public:
      int minEatingSpeed(vector<int>& piles, int h) {
            int low = 1;
            int high = *max_element(piles.begin(), piles.end());
            int ans = high;

            while (low <= high) {
                  int mid = low + (high - low) / 2; 
                  long long total_hours = 0;

                  for (int pile : piles) {
                  total_hours += ceil((double)pile/mid); // Same as ceil(pile / mid)
                  }

                  if (total_hours <= h) {
                  ans = mid;
                  high = mid - 1; // Try a smaller speed
                  } else {
                  low = mid + 1;  // Need to increase speed
                  }
            }

            return ans;
      }
};

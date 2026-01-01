//Range = Maximum - Minimum

class Solution {
public:
      long long subArrayRanges(vector<int>& nums) {
            int n = nums.size();
            vector<long long> leftMin(n), rightMin(n);
            vector<long long> leftMax(n), rightMax(n);
            stack<int> st;

            // ----- Minimum contribution -----
            for (int i = 0; i < n; i++) {
                  while (!st.empty() && nums[st.top()] > nums[i])
                  st.pop();
                  leftMin[i] = st.empty() ? (i + 1) : (i - st.top());
                  st.push(i);
            }

            while (!st.empty()) st.pop();

            for (int i = n - 1; i >= 0; i--) {
                  while (!st.empty() && nums[st.top()] >= nums[i])
                  st.pop();
                  rightMin[i] = st.empty() ? (n - i) : (st.top() - i);
                  st.push(i);
            }

            while (!st.empty()) st.pop();

            // ----- Maximum contribution -----
            for (int i = 0; i < n; i++) {
                  while (!st.empty() && nums[st.top()] < nums[i])
                  st.pop();
                  leftMax[i] = st.empty() ? (i + 1) : (i - st.top());
                  st.push(i);
            }

            while (!st.empty()) st.pop();

            for (int i = n - 1; i >= 0; i--) {
                  while (!st.empty() && nums[st.top()] <= nums[i])
                  st.pop();
                  rightMax[i] = st.empty() ? (n - i) : (st.top() - i);
                  st.push(i);
            }

            long long sumMin = 0, sumMax = 0;
            for (int i = 0; i < n; i++) {
                  sumMin += nums[i] * leftMin[i] * rightMin[i];
                  sumMax += nums[i] * leftMax[i] * rightMax[i];
            }

            return sumMax - sumMin;
      }
};

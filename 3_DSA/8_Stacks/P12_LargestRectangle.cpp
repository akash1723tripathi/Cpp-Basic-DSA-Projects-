//Brute using next smaller and previous smaller

class Solution {
public:
      int largestRectangleArea(vector<int>& heights) {
            int n = heights.size();
            vector<int> pse(n), nse(n);
            stack<int> st;

            // -------- PSE (Previous Smaller Element) --------
            for (int i = 0; i < n; i++) {
                  while (!st.empty() && heights[st.top()] >= heights[i]) {
                  st.pop();
                  }
                  pse[i] = st.empty() ? -1 : st.top();
                  st.push(i);
            }

            // clear stack
            while (!st.empty()) st.pop();

            // -------- NSE (Next Smaller Element) --------
            for (int i = n - 1; i >= 0; i--) {
                  while (!st.empty() && heights[st.top()] >= heights[i]) {
                  st.pop();
                  }
                  nse[i] = st.empty() ? n : st.top();
                  st.push(i);
            }

            // -------- Compute Max Area --------
            int maxArea = 0;
            for (int i = 0; i < n; i++) {
                  int width = nse[i] - pse[i] - 1;
                  int area = heights[i] * width;
                  maxArea = max(maxArea, area);
            }

            return maxArea;
      }
};


//Optimal 

class Solution {
public:
      int largestRectangleArea(vector<int>& heights) {
            stack<int> st;
            int maxArea = 0;
            int n = heights.size();

            for (int i = 0; i <= n; i++) {
                  int currHeight = (i == n) ? 0 : heights[i];

                  while (!st.empty() && currHeight < heights[st.top()]) {
                  int h = heights[st.top()];
                  st.pop();

                  int right = i;
                  int left = st.empty() ? -1 : st.top();
                  int width = right - left - 1;

                  maxArea = max(maxArea, h * width);
                  }
                  st.push(i);
            }
            return maxArea;
      }
};

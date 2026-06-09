class Solution {
public:
      int maximalRectangle(vector<vector<char>>& matrix) {
            if (matrix.empty()) return 0;

            int rows = matrix.size();
            int cols = matrix[0].size();

            vector<int> heights(cols, 0);
            int maxArea = 0;

            for (int r = 0; r < rows; r++) {
                  // Build histogram for current row
                  for (int c = 0; c < cols; c++) {
                  if (matrix[r][c] == '1')
                        heights[c] += 1;
                  else
                        heights[c] = 0;
                  }

                  // Largest Rectangle in Histogram
                  stack<int> st;
                  for (int i = 0; i <= cols; i++) {
                  int currHeight = (i == cols) ? 0 : heights[i];

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
            }

            return maxArea;
      }
};

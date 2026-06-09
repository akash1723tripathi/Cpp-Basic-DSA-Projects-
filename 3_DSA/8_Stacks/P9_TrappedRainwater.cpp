// Brute-Basic -- suffix max and prefix max arrays
class Solution {
public:
      int trap(vector<int>& h) {
            int n = h.size();
            vector<int> left(n), right(n);
            
            left[0] = h[0];
            for (int i = 1; i < n; i++)
                  left[i] = max(left[i-1], h[i]);

            right[n-1] = h[n-1];
            for (int i = n-2; i >= 0; i--)
                  right[i] = max(right[i+1], h[i]);

            int water = 0;
            for (int i = 0; i < n; i++)
                  water += min(left[i], right[i]) - h[i];

            return water;
      }

};


// Optimized -- two pointer approach

int trap(vector<int>& height) {
      int left = 0, right = height.size() - 1;
      int leftMax = 0, rightMax = 0;
      int water = 0;

      while (left < right) {
            if (height[left] < height[right]) {
                  leftMax = max(leftMax, height[left]);
                  water += leftMax - height[left];
                  left++;
            } else {
                  rightMax = max(rightMax, height[right]);
                  water += rightMax - height[right];
                  right--;
            }
      }
      return water;
}



// Stack based approach

int trap(vector<int>& h) {
      stack<int> st;
      int water = 0;

      for (int i = 0; i < h.size(); i++) {
            while (!st.empty() && h[i] > h[st.top()]) {
                  int mid = st.top(); 
                  st.pop();
                  if (st.empty()) break;

                  int left = st.top();
                  int right = i;
                  int width = right - left - 1;
                  int height = min(h[right], h[left]) - h[mid];
                  water += width * height;
            }
            st.push(i);
      }
      return water;
}

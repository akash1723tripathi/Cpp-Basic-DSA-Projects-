// using map + brute
class Solution {
public:
      vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            int m = nums1.size();
            int n = nums2.size();
            vector<int> ans(m, -1);

            unordered_map<int, int> indexMap;
            for (int i = 0; i < n; ++i) {
                  indexMap[nums2[i]] = i;
            }

            for (int i = 0; i < m; ++i) {
                  int val = nums1[i];
                  
                  int idx = indexMap[val];  

                  for (int j = idx + 1; j < n; ++j) {
                  if (nums2[j] > val) {
                        ans[i] = nums2[j];
                        break;
                  }
                  }
            }

            return ans; 
      }
};


//approach with monotonic stack 
//leetcode solution
class Solution {
public:
      vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            unordered_map<int,int> mp;
            stack<int> st;

            for(auto x : nums2){
                  while(!st.empty() && x>st.top()){
                  mp[st.top()]=x;
                  st.pop();
                  }
                  st.push(x);
            }

            vector<int> ans;
            ans.reserve(nums1.size());

            for(auto v:nums1){
                  if(mp.count(v)) ans.push_back(mp[v]);
                  else ans.push_back(-1);
            }

            return ans; 
      }
};

//gfg
class Solution {
  public:
      vector<int> nextLargerElement(vector<int>& arr) {
            int n = arr.size();
            vector<int> ans(n, -1);
            stack<int> st;
      
            for (int i = 0; i < n; ++i) {
                  while (!st.empty() && arr[i] > arr[st.top()]) {
                  ans[st.top()] = arr[i];
                  st.pop();
                  }
                  st.push(i);
            }
            return ans;
      }
};
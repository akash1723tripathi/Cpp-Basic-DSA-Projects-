//Brute force 
class Solution {
public:
      void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int left = 0;
            int right = 0;
            int index = 0;
            vector<int> nums3(m + n);

            // Merge both arrays into nums3
            while(left < m && right < n){
                  if(nums1[left] < nums2[right]){
                  nums3[index++] = nums1[left++];
                  } else {
                  nums3[index++] = nums2[right++];
                  }
            }

            // Copy remaining elements
            while(left < m){
                  nums3[index++] = nums1[left++];
            }
            while(right < n){
                  nums3[index++] = nums2[right++];
            }

            // Copy back to nums1
            for(int i = 0; i < m + n; i++){
                  nums1[i] = nums3[i];
            }
    }
};


//space Optimized
class Solution {
public:
      void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int i = m - 1;
            int j = n - 1;
            int k = m + n - 1;

            while(i >= 0 && j >= 0) {
                  if(nums1[i] > nums2[j]) {
                  nums1[k--] = nums1[i--];
                  } else {
                  nums1[k--] = nums2[j--];
                  }
            }

            while(j >= 0) {
                  nums1[k--] = nums2[j--];
            }
      }
};


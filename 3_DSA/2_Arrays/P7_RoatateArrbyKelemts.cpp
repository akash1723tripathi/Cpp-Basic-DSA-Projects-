//APPROACH 1
//left rotate
class Solution {
public:
      void rotateLeft(vector<int>& nums, int k) {
            int n = nums.size();
            k = k % n;  // Normalize k

            // Step 1: Store the first k elements in temp
            vector<int> temp(k);
            for (int i = 0; i < k; i++) {
                  temp[i] = nums[i];
            }

            // Step 2: Shift the remaining elements to the left
            for (int i = k; i < n; i++) {
                  nums[i - k] = nums[i];
            }

            // Step 3: Copy temp elements to the end
            for (int i = 0; i < k; i++) {
                  nums[n - k + i] = temp[i];
            }
      }
};



//right rotate
class Solution {
public:
      void rotate(vector<int>& nums, int k) {
            int n=nums.size();
            k=k%n; //normalize for higher values
            vector<int> temp(k);
            for(int i=0;i<k;i++){
                  temp[i]=nums[n-k+i];
            }

            //step 1 : shifting elements by k position forward
            for(int i=n-k-1;i>=0;i--){
                  nums[i+k]=nums[i];
            }

            //step2: re-inserting temp values in nums
            for(int i=0;i<k;i++){
                  nums[i]=temp[i];
            }
      }
};


//APPROACH 2

class Solution {
public:
      void rotate(vector<int>& nums, int k) {
            int n = nums.size();
            k = k % n;

            // Reverse first k elements
            reverse(nums.begin(), nums.begin() + k);
            // Reverse remaining elements
            reverse(nums.begin() + k, nums.end());
            // Reverse the whole array
            reverse(nums.begin(), nums.end());
      }
};

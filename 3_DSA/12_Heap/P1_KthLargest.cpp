//Kth Largeset Element in an Array
class Solution {
  public:
    // Function to return kth largest element from an array.
    int KthLargest(vector<int> &arr, int k) {
        priority_queue<int,vector<int>,greater<int>> minHeap;
        
        for(int ele:arr){
            minHeap.push(ele);
            if(minHeap.size()>k) minHeap.pop();
        }
        
        return minHeap.top();
        
    }
};



//Kth Smallest Element in an Array

class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> maxHeap;
        
        for(int ele:arr){
            maxHeap.push(ele);
            if(maxHeap.size()>k) maxHeap.pop();
        }
        
        return maxHeap.top();
        
    }
};











//Basic code
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> min_heap(nums.begin(), nums.begin() + k);
        
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > min_heap.top()) {
                min_heap.pop();
                min_heap.push(nums[i]);
            }
        }
        
        return min_heap.top();
    }
};
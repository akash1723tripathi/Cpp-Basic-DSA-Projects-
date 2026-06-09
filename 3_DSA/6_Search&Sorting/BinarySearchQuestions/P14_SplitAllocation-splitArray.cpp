//Book Allocation Problem + Split Array + Painter's Partition

class Solution {
private:
      int countStudents(vector<int>& nums, int pages){
            int st = 1;
            long long pagesSt = 0;
            for(int i=0;i<nums.size();i++){
                  if(pagesSt + nums[i] <= pages){
                  pagesSt += nums[i];
                  }else{
                  st++;
                  pagesSt = nums[i];
                  }
            }
      return st;
      }

      int findPages(vector<int>& nums,int n, int k){
            if(k>n) return -1;
            int low = *max_element(nums.begin(),nums.end());
            int high = accumulate(nums.begin(),nums.end(),0);
            while(low<=high){
                  int mid=low+(high-low)/2;
                  int students = countStudents(nums,mid);
                  if(students>k){
                  low=mid+1;
                  }else{
                  high=mid-1;
                  }
            }
      return low;
      }
public:
      int splitArray(vector<int>& nums, int k) {
            int n = nums.size();
            return findPages(nums,n,k);
      }
};



//Tailored for Split Array
class Solution {
private:
      int count(vector<int>& nums, int mid){
            int sbArr = 1; //no. of subarrays
            long long sbSum = 0; //initial sum to be 0 for sub array
            for(int i=0;i<nums.size();i++){
                  if(sbSum + nums[i] <= mid){
                  sbSum += nums[i];
                  }else{
                  sbArr++;
                  sbSum = nums[i];
                  }
            }
      return sbArr;
      }

public:
      int splitArray(vector<int>& nums, int k) {
            int n = nums.size();
            if(k>n) return -1;
            int low = *max_element(nums.begin(),nums.end());
            int high = accumulate(nums.begin(),nums.end(),0);
            while(low<=high){
                  int mid=low+(high-low)/2;
                  if(count(nums,mid)>k){
                  low=mid+1;
                  }else{
                  high=mid-1;
                  }
            }
      return low;
      }
};
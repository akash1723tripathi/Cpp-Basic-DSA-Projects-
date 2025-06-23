// approach 1 brute --TLE
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> sumstore;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                sumstore.push_back(sum);
            }
        }
        sort(sumstore.begin(), sumstore.end());
        return sumstore.back();  // or sumstore[sumstore.size() - 1]
    }
};


//Approach 2 : better -- Still TLE

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
      int maxSubArray(vector<int>& nums) {
            int n = nums.size();
            int maxi = INT_MIN;
            for (int i = 0; i < n; i++) {
                  int sum = 0;
                  for (int j = i; j < n; j++) {
                  sum += nums[j];
                  maxi=max(maxi,sum);
                  }
            }
            return maxi;
      }
};



//Optimal - Kadane`s Algo ---to return sum/subarray

class Solution {
public:
      int maxSubArray(vector<int>& nums) {
            int n = nums.size();
            int maxi = INT_MIN;
            int sum = 0;
            int start;
            int subStart =-1;
            int subEnd =-1;
            for(int i=0;i<n;i++){
                  if(sum==0){
                        start=i;
                  }
                  sum += nums[i];
                  if(sum>maxi){
                  maxi=sum;
                  subStart= start;
                  subEnd= i;

                  }
                  if(sum<0){
                  sum=0;
                  }
            }
            return maxi;// return nums[subStart,subEnd];
      }
};
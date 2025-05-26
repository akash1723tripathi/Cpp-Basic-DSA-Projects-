//Brute Approach
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x=0;
        int n = nums.size();
        for(int i=0;i<=n;i++){
            bool flag = false;
            for(int j=0;j<=n-1;j++){
                if(nums[j]==i){
                    flag=true;
                    break;
                }
            }
            if(flag==0){
                return i;
            }
        }
        return -1;
    }
};

// Better using Hash array
class Solution {
public:
      int missingNumber(vector<int>& nums) {
            int hash[n+1]={0};
            for(int i=0;i<n;i++){
                  hash[nums[i]]=1;
            }
            for(int j=0;j<n;j++){
                  if(hash[i]==0){
                        return i;
                  }
            }
            return -1;
      }
};

//Optimal Appraoch 
// 1. Using Sum Method
class Solution {
public:
      int missingNumber(vector<int>& nums) {
            int n = nums.size();
            int sum = (n*(n+1))/2;
            int s1=0;
            for(int i=0;i<=n-1;i++){
                  s1+=nums[i];
            }
            return sum-s1;
      }
};


//2. Using the XOR method 
class Solution {
public:
      int missingNumber(vector<int>& nums) {
            int n=nums.size();
            int XOR1=0;
            for(int i=1;i<=n;i++){
                  XOR1 = XOR1^i;
            }

            int XOR2=0;
            for(int i=0;i<n;i++){
                  XOR2 = XOR2^nums[i];
            }

            return XOR1^XOR2;
      }
};
//better 
class Solution {
public:
      vector<vector<int>> fourSum(vector<int>& nums, int target) {
            int n = nums.size();
            set<vector<int>> st;
            for(int i=0;i<n;i++){
                  for(int j=i+1;j<n;j++){
                  set<long long> hash;
                  for(int k=j+1;k<n;k++){
                        //for fourth element
                        long long sum = nums[i]+nums[j];
                              long long int Q = target -(sum+nums[k]);
                        if(hash.find(Q) != hash.end()){
                              vector<int> temp = {nums[i],nums[j],nums[k],(int)Q};
                              sort(temp.begin(),temp.end());
                              st.insert(temp);
                        }
                        hash.insert(nums[k]);
                  }
                  }
            }
            vector<vector<int>> ans(st.begin(),st.end());
            return ans;
      }
};


//optimal
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
            int n = nums.size();
            vector<vector<int>> ans;
            sort(nums.begin(),nums.end()); 

            for(int i=0;i<n;i++){
                  if(i>0 && nums[i]==nums[i-1]) continue;
                  for(int j=i+1;j<n;j++){
                        if(j>i+1 && nums[j]==nums[j-1]) continue;
                        int k=j+1;
                        int l=n-1;
                        while(k<l){
                              long long sum = nums[i]+nums[j];
                              sum += nums[k]+nums[l];

                              if(sum<target){
                                    k++;
                              }
                              else if(sum>target){
                                    l--;
                              }else{
                                    ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                                    k++;
                                    l--;
                                    while(k<l && nums[k]==nums[k-1]) k++;
                                    while(k<l && nums[l]==nums[l+1]) l--;
                              }
                        }
                  }
            }
            return ans;
    }
};
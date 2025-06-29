//better
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) { //k--target
	set<vector<int>> st;
        for(int i=0;i<n;i++){
            set<int> hash;
            for(int j=i+1;j<n;j++){
				int q= K -(arr[i]+arr[j]);
                if(hash.find(q) != hash.end()){
                    vector<int> temp = {arr[i],arr[j],q};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hash.insert(arr[j]);
            }
        }
      vector<vector<int>> ans(st.begin(),st.end());
      return ans;
}


//optimal --for problem to achieve sum ==target, replace 0-->target 
class Solution {
public:
      vector<vector<int>> threeSum(vector<int>& nums) {
            int n = nums.size();
            vector<vector<int>> ans;
            sort(nums.begin(),nums.end());
            for(int i=0;i<n;i++){
                  if(i>0 && nums[i]== nums[i-1]) continue;
                  int j=i+1;
                  int k=n-1;
                  while(j<k){
                        int sum = nums[i]+nums[j]+nums[k];
                        if(sum<0){
                              j++;
                        }
                        else if(sum>0){ 
                              k--;
                        }
                        else{
                              vector<int> temp = {nums[i],nums[j],nums[k]};
                              ans.push_back(temp);
                              j++;
                              k--;
                              while(j<k && nums[j]==nums[j-1]) j++;
                              while(j<k && nums[k]==nums[k+1]) k--;
                        }
                  }
            }
            return ans;
    }
};
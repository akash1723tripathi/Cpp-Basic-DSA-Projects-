// majority element refers to the element appearing more than n/2 times

//brute force -- code 360
int findMajorityElement(int arr[], int n) {
	for(int i=0;i<n;i++){
		int cnt=0;
		for(int j=0;j<n;j++){
			if(arr[i]==arr[j]){
				cnt++;
			}
			if(cnt>(n/2)){
				return arr[i];
			}
		}
	}
	return -1;
}

//better-- hashmap
int findMajorityElement(int arr[], int n) {
      unordered_map<int, int> count;
      for (int i = 0; i < n; i++) {
            count[arr[i]]++;
            if (count[arr[i]] > n/2) {
                  return arr[i]; // Early exit if majority found
            }
      }
      return -1;
}


//optimal-- Moore`s Voting Algo 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
            int cnt=0;
            int element;
            for(int i=0;i<nums.size();i++){
                  if(cnt==0){
                  element=nums[i];
                  cnt=1;    
                  }
                  else if(nums[i]==element){
                  cnt++;
                  }
                  else{
                  cnt--;
                  }
            }

            int cnt1=0;
            for(int i=0;i<nums.size();i++){
                  if(nums[i]=element){
                  cnt1++;
                  }
            }
            if(cnt1 >= (nums.size()/2)){
                  return element;
            }
            return 0;        
    }
};
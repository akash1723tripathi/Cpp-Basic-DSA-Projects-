class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        if(k<=0){
            return 0;
        }
        unordered_map<int,int> mp;
        int sum=0;

        for(int num : nums){
            mp[num]++;
        }

        for(const auto& pair : mp){
            int ele = pair.first;
            int freq = pair.second;

            if(freq % k ==0){
                sum += ele*freq;
            }
        }
        return sum;
    }
};
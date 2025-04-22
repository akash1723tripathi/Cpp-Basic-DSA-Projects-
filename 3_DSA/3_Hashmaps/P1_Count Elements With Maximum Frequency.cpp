#include<unordered_map>
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> map;
        //frequency calculations 
        for(int i :nums){
            map[i]++;
        }

        int maxi = 0;
        for(auto i : map ){
            if(i.second > maxi){
                maxi = i.second;
            }
        }
        int count = 0;
        for(auto i:map){
            if(i.second == maxi){
                count+=maxi;
            }
        }
        return count;
    }
};
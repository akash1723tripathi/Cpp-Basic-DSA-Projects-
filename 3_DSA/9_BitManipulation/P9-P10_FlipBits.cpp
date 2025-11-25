// Leetcode -- Flip bits  to convert A to B
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n = start^goal;
        int cnt=0;
        while(n>0){
            cnt+= n&1;
            n=n>>1;
        }
        return cnt;
    }
};
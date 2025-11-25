//Only for a single number
class Solution {
  public:
      int countSetBits(int n) {
            int cnt = 0;
            while(n>0){
                  cnt += n&1;
                  n = n>>1;
            }

            //while(n>0){        ---using the rightmost set bit technique
                  // n=n&(n-1);
                  // cnt++;
            //}

            return cnt;
      }
};












//Find the total count of set bits for all numbers from 1 to n (both inclusive).
class Solution {
  public:
      int countSetBits(int n) {
            int cnt = 0;
            for(int i = 1; i <= n; i++){
                  int x = i;            // don't destroy i
                  while(x > 0){
                  cnt += (x & 1);
                  x >>= 1;
                  }
            }
            return cnt;
      }
};







class Solution {
  public:
      int countSetBits(int n) {
            if (n == 0) return 0;

            int x = log2(n);
            int power = 1 << x;

            int msbBits = x * (power >> 1);
            int msbRemain = n - power + 1;

            return msbBits + msbRemain + countSetBits(n - power);
      }
};

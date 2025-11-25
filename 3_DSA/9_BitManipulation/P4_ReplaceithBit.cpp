// based on 0 indexing from right to left

class Solution {
public:
      int replaceBit(int n, int k) {
            int totalBits = floor(log2(n)) + 1;
            int pos = totalBits - k; 

            if (pos < 0) return n;  

            if (n & (1 << pos)) {
                  n = n & ~(1 << pos);  
            }

            return n;
      }
};

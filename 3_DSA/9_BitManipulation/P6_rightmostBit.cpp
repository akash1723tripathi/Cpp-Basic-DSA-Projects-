//Set the rightmost unset bit
class Solution {
  public:
      int setBit(int n) {
            n = n|n+1;
            return n;
      }
};


//remove the rightmost set bit
class Solution {
  public:
      int removeBit(int n) {
            n = n&n-1;
            return n;
      }
};
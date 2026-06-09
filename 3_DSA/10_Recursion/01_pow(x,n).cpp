class Solution {
public:
    double myPow(double x, int n) {
        // Base case: Anything to the power of 0 is 1
        if (n == 0) return 1.0;
        
        // Handle negative powers and prevent integer overflow
        if (n < 0) {
            // We use -(n + 1) to avoid overflow when n is exactly -2^31.
            // Because -(-2^31) exceeds the 32-bit int limit, but -(-2^31 + 1) is safe.
            return (1.0 / x) * myPow(1.0 / x, -(n + 1));
        }
        
        // Recursive step: Divide the power by 2
        double half = myPow(x, n / 2);
        
        // If the power is even, we just square the half-result
        if (n % 2 == 0) {
            return half * half;
        } 
        // If the power is odd, we square the half-result and multiply by one more x
        else {
            return half * half * x;
        }
    }
};
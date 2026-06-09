class Solution {
private:
    // Define the modulo constant as required by the problem
    long long MOD = 1e9 + 7;

    // Our trusty Fast Binary Exponentiation (with Modulo)
    long long power(long long base, long long exp) {
        if (exp == 0) return 1;
        
        long long half = power(base, exp / 2);
        
        // Multiply and apply modulo
        long long half_squared = (half * half) % MOD;
        
        if (exp % 2 == 0) {
            return half_squared;
        } else {
            // If odd, multiply by base one more time and apply modulo again
            return (half_squared * base) % MOD;
        }
    }

public:
    int countGoodNumbers(long long n) {
        // Calculate how many even and odd positions we have
        long long odd_count = n / 2;
        long long even_count = (n + 1) / 2;
        
        // Calculate 5^(even_count) % MOD
        long long even_combos = power(5, even_count);
        
        // Calculate 4^(odd_count) % MOD
        long long odd_combos = power(4, odd_count);
        
        // Multiply them together and apply the final modulo
        return (even_combos * odd_combos) % MOD;
    }
};
class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        int sign = 1;
        int result = 0;

        // Step 1: The Cleanup Phase (Whitespace)
        // Skip all leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: The Sign Phase
        // Check if the current character is a '+' or '-'
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++; // Move past the sign character
        }

        // Step 3 & 4: Accumulation and Overflow Phase
        // Keep reading while the character is a valid digit
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0'; // Convert char to integer

            // Overflow Check BEFORE multiplying by 10
            // INT_MAX is 2147483647. INT_MAX / 10 is 214748364.
            // If result is already > 214748364, multiplying by 10 will overflow.
            // If result == 214748364, adding a digit > 7 will overflow.
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            // Build the number
            result = result * 10 + digit;
            i++;
        }

        // Apply the sign to the final result
        return result * sign;
    }
};
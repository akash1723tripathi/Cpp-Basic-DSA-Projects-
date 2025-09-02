class Solution {
public:
      int myAtoi(string s) {
            int i = 0, n = s.size();

            // 1. Skip leading whitespaces
            while (i < n && s[i] == ' ') i++;

            // 2. Handle optional sign
            int sign = 1;
            if (i < n && (s[i] == '+' || s[i] == '-')) {
                  if (s[i] == '-') sign = -1;
                  i++;
            }

            // 3. Convert digits to number
            long result = 0; // use long to check overflow
            while (i < n && isdigit(s[i])) {
                  int digit = s[i] - '0';

                  // 4. Check overflow before multiplying
                  if (result > (INT_MAX - digit) / 10) {
                  return (sign == 1) ? INT_MAX : INT_MIN;
                  }

                  result = result * 10 + digit;
                  i++;
            }

            return (int)(sign * result);
      }
};
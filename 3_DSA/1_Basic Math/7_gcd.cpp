#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
      while (b != 0)
      {
            int temp = b;
            b = a % b;
            a = temp;
      }
      return a;
}

int modLargeNumber(const string &b, int a)
{
      int result = 0;
      for (char digit : b)
      {
            result = (result * 10 + (digit - '0')) % a;
      }
      return result;
}

int advancedGcd(int a, string b)
{
      if (a == 0)
            return 0;
      int b_mod_a = modLargeNumber(b, a);
      return gcd(a, b_mod_a);
}

#include <cmath>
bool isArmstrong(int num)
{
      // countDigits
      int len = (int)(log10(num) + 1);
      int r, sum = 0, x = num;

      while (x != 0)
      {
            r = x % 10;
            r = pow(r, len);
            sum += r;
            x = x / 10;
      }
      if (num == sum)
      {
            return true;
      }
      else
      {
            return false;
      }
}
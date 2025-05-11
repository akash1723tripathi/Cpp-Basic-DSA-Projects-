class Solution
{
public:
      int reverse(int x)
      {
            int newNum = 0, y;
            while (x != 0)
            {
                  y = x % 10;
                  //for the condition to put boundaries of the container 
                  if (newNum > INT32_MAX / 10 || newNum < INT32_MIN / 10)
                        return 0;
                  newNum = newNum * 10 + y;
                  x = x / 10;
            }
            return newNum;
      }
};

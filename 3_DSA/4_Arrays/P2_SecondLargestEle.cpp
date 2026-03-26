// approach 1


int findSecondLargest(int n, vector<int> &arr)
{
      int largest = INT_MIN;
      int sec_largest = INT_MIN;
      // to find largest
      for (int i = 0; i < n; i++)
      {
            if (arr[i] > largest)
            {
                  largest = arr[i];
            }
      }
      // second largest
      for (int i = 0; i < n; i++)
      {
            if (arr[i] > sec_largest && arr[i] != largest)
            {
                  sec_largest = arr[i];
            }
      }
      
      if (sec_largest == INT_MIN)
      {
            return -1;
      }
      else
      {
            return sec_largest;
      }
}

// approach 2

#include <bits/stdc++.h>
using namespace std;

int findSecondLargest(int n, vector<int> &arr)
{
      int largest = INT_MIN;
      int sec_largest = INT_MIN;

      for (int i = 0; i < n; i++)
      {
            if (arr[i] > largest)
            {
                  sec_largest = largest;
                  largest = arr[i];
            }
            else if (arr[i] < largest && arr[i] > sec_largest)
            {
                  sec_largest = arr[i];
            }
      }

      if (sec_largest == INT_MIN)
             return -1;
      return sec_largest;
}

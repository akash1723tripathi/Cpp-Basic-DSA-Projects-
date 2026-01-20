class Solution
{
public:
      int minCost(vector<int> &arr){
            priority_queue<int, vector<int>, greater<int>> mH(arr.begin(), arr.end());
            int cost = 0;

            while (mH.size() > 1)
            {
                  int n1 = mH.top(); mH.pop();
                  int n2 = mH.top(); mH.pop();
                  int n = n1 + n2;
                  cost += n;
                  mH.push(n);
            }

            return cost;
      }
};
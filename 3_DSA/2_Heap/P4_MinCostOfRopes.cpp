class Solution{
      long long  minCost(long long arr[],long long n){
            priority_queue<long long, vector<long long>, greater<long long>> mh;
            for(int i=0 ;i<n;i++ ){
                  mh.push(arr[i]);  
            }
            long long cost;
            while(mh.size()>1){
                  long long n1 = mh.top();
                  mh.pop();
                  long long n2 = mh.top();
                  mh.pop();

                  long long sum = n1+n2;
                  cost = cost + sum;
                  mh.push(sum);
            }      
            return cost;
      }
};
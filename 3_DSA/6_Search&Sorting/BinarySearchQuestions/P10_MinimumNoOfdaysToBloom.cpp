class Solution {
private:
    bool possible(vector<int>& bloomDay,int day, int m, int k,int n){
            int cnt=0,noB=0;
            for(int i=0;i<n;i++){
                  if(bloomDay[i]<=day){
                  cnt++;
                  }else{
                  noB+=(cnt/k);
                  cnt=0;
                  }
            }
            noB +=(cnt/k);
            return noB>=m;
      }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
            int n = bloomDay.size();
            long long size = (1LL*m)*(1LL*k);
            
            if(size>n){
                  return -1;
            }

            int low = *min_element(bloomDay.begin(),bloomDay.end());
            int high = *max_element(bloomDay.begin(),bloomDay.end());


            while(low <= high){
                  int mid = low + ((high-low)/2);
                  if(possible(bloomDay,mid,m,k,n)==true){
                  high=mid-1;
                  } else{
                  low=mid+1;
                  }
            }
      return low;
      }
};
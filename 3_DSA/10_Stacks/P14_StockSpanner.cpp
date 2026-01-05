//Brute force approach
class StockSpanner {
public:
      vector<int> prices; 
      StockSpanner() {}
      
      int next(int price) {
            prices.push_back(price);
            int cnt=1;
            for(int i=prices.size()-2;i>=0;i--){
                  if(prices[i]<=price){
                  cnt++;
                  }else{
                  break;
                  }
            }
            return cnt;
      }
};


// optimized approach using stack

class StockSpanner {
public:
      stack<pair<int,int>> st;
      int idx = -1;

      StockSpanner() {}

      int next(int price) {
            idx++;

            while (!st.empty() && st.top().first <= price) {
                  st.pop();
            }

            int pge = st.empty() ? -1 : st.top().second;
            int span = idx - pge ;

            st.push({price, idx});
            return span;
      }
};

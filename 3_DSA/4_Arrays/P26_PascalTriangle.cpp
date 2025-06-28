//to generate a row 
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex+1;
        long long ans=1;
        vector<int> ansRow;
        ansRow.push_back(ans);

        for(int i=1;i<n;i++){
            ans=ans*(n-i);
            ans = ans / i;
            ansRow.push_back(ans);
        }
        return ansRow;
    }
};



//to generate whole pascalTriangle
class Solution {
private:
      vector<int> genRow(int row){
            long long ans = 1;
            vector<int> ansRow;
            ansRow.push_back(ans);
            //i==colums
            for(int i=1;i<row;i++){
                  ans = ans*(row-i);
                  ans = ans / i;
                  ansRow.push_back(ans);
            }
            return ansRow;
      }
public:
      vector<vector<int>> generate(int numRows) {
            vector<vector<int>> ans;
            for(int i=1;i<=numRows;i++){
                  ans.push_back(genRow(i));
            }
            return ans;
      }
};
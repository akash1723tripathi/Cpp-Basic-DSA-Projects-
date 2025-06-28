//better Approach 
class Solution {
public:
      void setZeroes(vector<vector<int>>& matrix) {
            int m = matrix.size();              // Rows
            int n = matrix[0].size();           // Columns

            vector<int> row(m, 0);              // Row markers
            vector<int> col(n, 0);              // Column markers

            // Step 1: Mark the rows and columns that need to be zero
            for (int i = 0; i < m; ++i) {
                  for (int j = 0; j < n; ++j) {
                  if (matrix[i][j] == 0) {
                        row[i] = 1;
                        col[j] = 1;
                  }
                  }
            }

            // Step 2: Set matrix[i][j] to zero if its row or column is marked
            for (int i = 0; i < m; ++i) {
                  for (int j = 0; j < n; ++j) {
                  if (row[i] == 1 || col[j] == 1) {
                        matrix[i][j] = 0;
                  }
                  }
            }
      }
};


//optimal approach using SC = O(1)
class Solution {
public:
      void setZeroes(vector<vector<int>>& matrix) {
            int m = matrix.size();              // Rows
            int n = matrix[0].size();           // Columns

            int col0 = 1;                       // Flag for first column

            // Step 1: Mark rows and columns using first row and first column
            for (int i = 0; i < m; ++i) {
                  if (matrix[i][0] == 0) col0 = 0;
                  for (int j = 1; j < n; ++j) {
                  if (matrix[i][j] == 0) {
                        matrix[i][0] = 0;       // Mark row
                        matrix[0][j] = 0;       // Mark column
                  }
                  }
            }

            // Step 2: Set zeroes based on markers (excluding first row and first column)
            for (int i = 1; i < m; ++i) {
                  for (int j = 1; j < n; ++j) {
                  if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                        matrix[i][j] = 0;
                  }
                  }
            }

            // Step 3: Zero first row if needed
            if (matrix[0][0] == 0) {
                  for (int j = 0; j < n; ++j) {
                  matrix[0][j] = 0;
                  }
            }

            // Step 4: Zero first column if needed
            if (col0 == 0) {
                  for (int i = 0; i < m; ++i) {
                  matrix[i][0] = 0;
                  }
            }
      }
};

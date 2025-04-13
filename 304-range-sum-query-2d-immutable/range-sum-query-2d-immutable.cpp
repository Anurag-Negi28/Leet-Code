class NumMatrix {
    private:
    vector<vector<int>> preVector;
    public:
        NumMatrix(vector<vector<int>>& matrix) {
        // your code goes here
        // First calculate teh prefix sum
        int m = matrix.size();                                    // No. of Rows
        int n = matrix[0].size();                                 // No. of Columns
        preVector=vector<vector<int>> (m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                preVector[i][j]=matrix[i][j];
                if (i > 0)
                {
                    preVector[i][j] += preVector[i - 1][j];
                }
                if (j > 0)
                {
                    preVector[i][j] += preVector[i][j - 1];
                }
                if (i > 0 && j > 0)
                {
                    preVector[i][j] -= preVector[i - 1][j - 1];
                }
            }
        }
        }
        
        int sumRegion(int row1, int col1, int row2, int col2) {
            int sum=0;
            sum = preVector[row2][col2] 
            - (row1 > 0 ? preVector[row1 - 1][col2] : 0) 
            - (col1 > 0 ? preVector[row2][col1 - 1] : 0) 
            + (row1 > 0 && col1 > 0 ? preVector[row1 - 1][col1 - 1] : 0);
        
        return sum;
        }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
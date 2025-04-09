class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size()-1;
        int n=matrix[0].size()-1;
        if(target<matrix[0][0] || target>matrix[m][n]){
            return false;
        }
        int i=0,j=n;
        while(i<=m && j>=0){
            if(matrix[i][j]==target){
                return true;
            }
            else if(matrix[i][j]>=target){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};
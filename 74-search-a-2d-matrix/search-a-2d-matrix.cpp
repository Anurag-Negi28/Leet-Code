class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0;int high=n*m-1;int mid=0;int row;int col;
        while(low<=high){
            mid=(low+high)/2;
            row=mid/m;
            col=mid%m;
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]<target) low=mid+1;
            else high=mid-1;
        }
        return false;
    }
};
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<pair<int,int>> position;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    position.push_back({i,j});
                }
            }
        }
        //Make the row zero
        for(int i=0;i<position.size();i++){
            for(int j=0;j<n;j++){
                matrix[position[i].first][j]=0;
            }
        }
        //Make the column zero
        for(int i=0;i<position.size();i++){
            for(int j=0;j<m;j++){
                matrix[j][position[i].second]=0;
            }
        }
    }
};
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int startRow=0;
        int endRow=m-1;
        int startColumn=0;
        int endColumn=n-1;
        vector<int> spiral;
        //Outer loop for the boumdaries
        while(startRow<=endRow && startColumn<=endColumn){
            //First row
            for(int col=startColumn;col<=endColumn;col++){
                spiral.push_back(matrix[startRow][col]);
            }
            //last column
            for(int row=startRow+1;row<=endRow;row++){
                spiral.push_back(matrix[row][endColumn]);
            }
            //last row
            for(int col=endColumn-1;col>=startColumn;col--){
                if(startRow==endRow){//to avoid double printing of last spiral
                    break;
                }
                spiral.push_back(matrix[endRow][col]);
            }
            //first column
            for(int row=endRow-1;row>=startRow+1;row--){
                if(startColumn==endColumn){//to avoid double printing of last spiral
                    break;
                }
                spiral.push_back(matrix[row][startColumn]);
            }
            //Update vairiables
            startRow++;
            endRow--;
            startColumn++;
            endColumn--;
        }
        return spiral;
    }
};
class Solution {
public:
    vector<int> generateRow(int row){
        int ans=1;
        vector<int> resultRow;
        resultRow.push_back(1);
        for(int col=1;col<row;col++){
            ans=ans*(row-col);
            ans=ans/col;
            resultRow.push_back(ans);
        }
        return resultRow;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> temp;
        for(int i=1;i<=numRows;i++){
            temp.push_back(generateRow(i));
        }
        return temp;
    }
};
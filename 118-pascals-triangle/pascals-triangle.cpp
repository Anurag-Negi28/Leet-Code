class Solution {
public:
vector<int> generateRow(int n){
    vector<int> ans;
    ans.push_back(1);
    long long p=1;
    for(int col=1;col<n;col++){
        p=p*(n-col);
        p=p/col;
        ans.push_back(p);
    }
    return ans;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i=1;i<=numRows;i++){
            result.push_back(generateRow(i));
        }
    return result;
    }
};
class Solution {
public:
    int singleNumber(vector<int>& v) {
        int result=v[0];
        for(int i=1;i<v.size();i++){
            result=result^v[i];
        }
        return result;
    }
};
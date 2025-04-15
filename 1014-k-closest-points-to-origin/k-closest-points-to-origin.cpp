class Solution {
public:

    static bool compare(vector<int> s1, vector<int> s2)
    {
        return (s1[0] * s1[0]+s1[1] * s1[1])< (s2[0] * s2[0]+s2[1] * s2[1]);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(),points.end(),compare);
        vector<vector<int>> result;
        for(int i=0;i<k;i++){
            result.push_back(points[i]);
        }
        return result;
    }

};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> res;
        int n=nums.size();
        int rem;int a;
        for(int i=0;i<n;i++){
            a=nums[i];
            rem=target-nums[i];
            if(m.find(rem)!=m.end()){
                res.push_back(m[rem]);
                res.push_back(i);
            }
            m[a]=i;
        }
        return res;
    }
};
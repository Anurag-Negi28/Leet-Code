class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> res(2,0);
        int n=nums.size();
        int rem;int a;
        for(int i=0;i<n;i++){
            a=nums[i];
            rem=target-nums[i];
            if(m.find(rem)!=m.end()){
                res[0]=m[rem];
                res[1]=i;
            }
            m[a]=i;
        }
        return res;
    }
};
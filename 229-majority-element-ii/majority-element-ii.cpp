class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto& p:mp){
            if(p.second>(n/3)) res.push_back(p.first);
        }
        return res;
    }
};
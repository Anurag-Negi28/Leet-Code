class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        map<int,int> mp;
        int n=nums.size();
        int count=(int)(n/3)+1;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]==count) res.push_back(nums[i]);
            if(res.size()==2) break;
        }
        return res;
    }
};
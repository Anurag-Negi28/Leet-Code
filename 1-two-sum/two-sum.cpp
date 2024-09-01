class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++)
        {
            int x=target-nums[i];
            if(map.find(x)!=map.end())
            {
                result.push_back(map[x]);
                result.push_back(i);
            }
            map[nums[i]]=i;
        }
        return result;
    }
};
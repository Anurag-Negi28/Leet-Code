class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxSumSubarray= INT_MIN;
        int cs=0;
        for (int i = 0; i < n; i++)
        {
            cs = cs + nums[i];
            maxSumSubarray = max(maxSumSubarray, cs);
            if (cs < 0)
            {
                cs = 0;
            }
        }
        return maxSumSubarray;
    }
};
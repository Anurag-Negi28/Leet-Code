class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxSumSubarray= INT_MIN;
        int cs;
        for (int i = 0; i < n; i++)
        {
            if (cs < 0)
            {
                cs = 0;
            }
            cs = cs + nums[i];
            maxSumSubarray = max(maxSumSubarray, cs);
        }
        return maxSumSubarray;
    }
};
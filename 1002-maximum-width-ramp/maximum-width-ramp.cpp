class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> indices(n);

        // Initialize the array with indices
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }

        // Sort indices based on corresponding values in nums and ensure
        // stability
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return nums[i] != nums[j] ? nums[i] < nums[j] : i < j;
        });

        int minIndex = n;  // Minimum index encountered so far
        int maxWidth = 0;

        // Calculate maximum width ramp
        for (int i = 0; i < n; i++) {
            maxWidth = max(maxWidth, indices[i] - minIndex);
            minIndex = min(minIndex, indices[i]);
        }

        return maxWidth;
    }
};
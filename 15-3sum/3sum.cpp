class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        vector<vector<int>> ans;
    sort(num.begin(), num.end()); // Step 1: sort the array
    int n = num.size();

    for (int i = 0; i < n; i++) {
        // Skip duplicate values for i
        if (i > 0 && num[i] == num[i - 1]) continue;

        int j = i + 1;
        int k = n - 1;

        while (j < k) {
            int sum = num[i] + num[j] + num[k];

            if (sum < 0) {
                j++; // need a bigger sum
            } 
            else if (sum > 0) {
                k--; // need a smaller sum
            } 
            else {
                // Found a triplet
                ans.push_back({num[i], num[j], num[k]});
                j++;
                k--;

                // Skip duplicate j
                while (j < k && num[j] == num[j - 1]) j++;
                // Skip duplicate k
                while (j < k && num[k] == num[k + 1]) k--;
            }
        }
    }
    return ans;
    }
};
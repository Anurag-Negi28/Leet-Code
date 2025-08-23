class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a=m;
        for (int i = 0; i < n; i++) {
            nums1[a]=nums2[i];
            a++;
        }
        sort(nums1.begin(), nums1.end());
    }
};
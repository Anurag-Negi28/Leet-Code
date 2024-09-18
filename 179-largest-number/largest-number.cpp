unsigned long long ten[19]={1};
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        for(int i=1; i<19; i++)
            ten[i]=ten[i-1]*10LL;
        vector<int> idx(n), sz(n);
        iota(idx.begin(), idx.end(), 0);
        vector<string> s(n);
        int SZ=0;
        for(int i=0; i<n; i++){
            s[i]=to_string(nums[i]);
            sz[i]=s[i].size();
            SZ+=sz[i];
        }
        sort(idx.begin(), idx.end(), [&](int i,  int j){
            int len_i=sz[i], len_j=sz[j];
            unsigned long long x=nums[i], y=nums[j], X=x*ten[len_j], Y=y*ten[len_i];
            return X+y>Y+x;
        });
        if (nums[idx[0]]==0) return "0";
        string ans;
        ans.reserve(SZ);
        for(int i=0; i<n; i++)
            ans+=s[idx[i]];
        return ans;
    }
};




auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
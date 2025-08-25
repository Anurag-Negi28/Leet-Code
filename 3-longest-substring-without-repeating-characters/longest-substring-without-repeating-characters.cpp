class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> st;
        int n=s.length();
        int maxLen=1;
        int count=0;
        int left=0;int right=0;
        if(n==0) return 0;
        while(right<n){
            if(st.find(s[right])==st.end()){
                st.insert(s[right]);
                maxLen=max(maxLen,right-left+1);
                right++;
            }else{
                while(st.find(s[right])!=st.end()){
                st.erase(s[left]);
                left++;
                }
            }
        }
        return maxLen;
    }
};
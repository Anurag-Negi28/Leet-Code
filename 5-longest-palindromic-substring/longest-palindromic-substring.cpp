class Solution {
public:
    string expand(string s,int l, int r){
        while(l>=0 && r<s.length() && s[l]==s[r]){
            l--;
            r++;
        }
        return s.substr(l+1,r-l-1);
    }
    string longestPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.length();i++){
            string odd=expand(s,i,i);
            string even=expand(s,i,i+1);
            if(odd.size()>ans.size()) ans=odd;
            if(even.size()>ans.size()) ans=even;
        }
        return ans;
    }
};
class Solution {
public:
    int romanToInt(string s) {
        int result=0;
        map<char,int> mpp;
        mpp['I']=1;
        mpp['V']=5;
        mpp['X']=10;
        mpp['L']=50;
        mpp['C']=100;
        mpp['D']=500;
        mpp['M']=1000;
        int n=s.length();
        //result=mpp[s[i]]
        for (int i = 0; i < n; i++) {
            // If next value is bigger → subtract current
            if (i + 1 < n && mpp[s[i]] < mpp[s[i+1]]) {
                result -= mpp[s[i]];
            } else {
                result += mpp[s[i]];
            }
        }
        return result;
    }
};
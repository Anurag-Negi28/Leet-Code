class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int repeat=1;
        string newstr="";
        if (a.length() != 0) {
            repeat = (b.length() + a.length() - 1) / a.length();
        }
        // Repeat the string `a` `repeat` number of times
        for (int i = 0; i < repeat; ++i) {
            newstr += a;
        }
        // check current string
        if (match(newstr, b)) return repeat;

        // check one more repeat (to cover overlap case)
        newstr += a;
        repeat++;
        if (match(newstr, b)) return repeat;

        return -1;
    }
    bool match(string a,string b){
        for(int i=0;i<=a.length()-b.length();i++){
            if(b==a.substr(i,b.length())){
                return true;
            }
        }
        return false;
    }
};
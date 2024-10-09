class Solution {
public:
    int minAddToMakeValid(string s) {
     int openBrackets=0;
     int minAddsRequired=0;
     for(char ch:s)
     {
        if(ch=='(')
        {
            openBrackets++;
        }else{
            openBrackets>0?openBrackets--:minAddsRequired++;
        }
     }
     return openBrackets+minAddsRequired;
     }
};
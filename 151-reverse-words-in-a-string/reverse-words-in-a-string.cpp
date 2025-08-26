class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        istringstream iss(s);
        string word;
        while(iss>>word){
            words.push_back(word);
        }
        reverse(words.begin(),words.end());
        string result;
        for(auto ch:words){
            result+=" "+ch;
        }
        result.erase(0,1);
        return result;
    }
};
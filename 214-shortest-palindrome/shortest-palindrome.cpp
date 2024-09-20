class Solution {
public:
    string shortestPalindrome(string s) {
        // Reverse the original string
        string reversedString = string(s.rbegin(), s.rend());

        // Combine the original and reversed strings with a separator
        string combinedString = s + "#" + reversedString;

        // Build the prefix table for the combined string
        vector<int> prefixTable = buildPrefixTable(combinedString);

        // Get the length of the longest palindromic prefix
        int palindromeLength = prefixTable[combinedString.length() - 1];

        // Construct the shortest palindrome by appending the reverse of the
        // suffix
        string suffix = reversedString.substr(0, s.length() - palindromeLength);
        return suffix + s;
    }

private:
    // Helper function to build the KMP prefix table
    vector<int> buildPrefixTable(const string& s) {
        vector<int> prefixTable(s.length(), 0);
        int length = 0;

        // Build the table by comparing characters
        for (int i = 1; i < s.length(); i++) {
            while (length > 0 && s[i] != s[length]) {
                length = prefixTable[length - 1];
            }
            if (s[i] == s[length]) {
                length++;
            }
            prefixTable[i] = length;
        }
        return prefixTable;
    }
};
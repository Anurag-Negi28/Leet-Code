class Solution {
public:
    int minLength(string s) {
        int i = 0;
        while (i < s.length() - 1) {  // Ensure we always have at least 2 characters to check
            if (s.length()<2) {
                break;  // Prevent accessing out of bounds
            }
            
            string subs = s.substr(i, 2);  // Get a substring of two characters
            if (subs == "AB" || subs == "CD") {
                s.erase(i, 2);  // Erase the substring starting at i
                if (i > 0) i--;  // Move i back to recheck the previous position
            } else {
                i++;  // Move to the next character if no match
            }
        }
        return s.length();  // Return the final length of the modified string
    }
};

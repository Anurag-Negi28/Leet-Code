class Solution {
public:
    string trim(string s) {
    int start = 0, end = s.size() - 1;

    // Remove leading spaces
    while (start < s.size() && isspace(s[start])) start++;

    // Remove trailing spaces
    while (end >= 0 && isspace(s[end])) end--;

    // If string is all spaces
    if (start > end) return "";

    return s.substr(start, end - start + 1);
    }

    int myAtoi(string s) {
        string str=trim(s);
        if (str.empty()) return 0;
        int i = 0, n = str.size();
        int sign = 1;
        long result = 0;

        // Check sign
        if (str[i] == '+' || str[i] == '-') {
            sign = (str[i] == '-') ? -1 : 1;
            i++;
        }
        while (i < n && isdigit(str[i])) {
            result = result * 10 + (str[i] - '0');

            // Handle overflow before casting
            if (sign * result > INT_MAX) return INT_MAX;
            if (sign * result < INT_MIN) return INT_MIN;

            i++;
        }

        return (int)(sign * result);
    }
};
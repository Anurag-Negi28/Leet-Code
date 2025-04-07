class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    if (s1.length() > s2.length()) return false;

    vector<int> freq1(26, 0), freq2(26, 0);

    // Count frequencies of characters in s1
    for (char c : s1) {
        freq1[c - 'a']++;
    }

    // Initialize the first window in s2
    for (int i = 0; i < s1.length(); i++) {
        freq2[s2[i] - 'a']++;
    }

    // Check if the first window is a permutation
    if (freq1 == freq2) return true;

    // Slide the window over s2
    for (int i = s1.length(); i < s2.length(); i++) {
        // Add the new character to the window
        freq2[s2[i] - 'a']++;
        // Remove the old character from the window
        freq2[s2[i - s1.length()] - 'a']--;

        // Check if the current window is a permutation
        if (freq1 == freq2) return true;
    }

    return false;
    }
};
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // allowedBits will represent the bitmask of allowed characters
        int allowedBits = 0;

        // Set the corresponding bit for each character in allowed
        for (int i = 0; i < allowed.length(); i++) {
            allowedBits |= 1 << (allowed[i] - 'a');
        }

        int consistentCount = 0;

        // Iterate through each word in the words array
        for (string& word : words) {
            bool isConsistent = true;

            // Check each character in the word
            for (int i = 0; i < word.length(); i++) {
                // Calculate the bit position for the current character
                int bit = (allowedBits >> (word[i] - 'a')) & 1;

                // If the bit is 0, the character is not allowed
                if (bit == 0) {
                    isConsistent = false;
                    break;
                }
            }

            // If the word is consistent, increment the count
            if (isConsistent) {
                consistentCount++;
            }
        }

        return consistentCount;
    }
};
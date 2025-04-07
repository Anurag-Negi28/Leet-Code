class Solution {
public:
    int compress(vector<char> &chars)
    {
        int n = chars.size();
        int writeIndex = 0; // Index to write the compressed characters
        int i = 0;          // Index to read the characters

        while (i < n)
        {
            char current = chars[i];
            int count = 0;

            // Count consecutive characters
            while (i < n && chars[i] == current)
            {
                count++;
                i++;
            }

            // Write the character
            chars[writeIndex++] = current;

            // Write the count if greater than 1
            if (count > 1)
            {
                string countStr = to_string(count);
                for (char c : countStr)
                {
                    chars[writeIndex++] = c;
                }
            }
        }

        // Resize the vector to the new length
        chars.resize(writeIndex);

        return writeIndex; // Return the length of the compressed array
    }
};
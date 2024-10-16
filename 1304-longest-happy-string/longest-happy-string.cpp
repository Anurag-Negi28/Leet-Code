class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int curra = 0, currb = 0, currc = 0;
        // Maximum total iterations possible is given by the sum of a, b and c.
        int totalIterations = a + b + c;
        string ans = "";

        for (int i = 0; i < totalIterations; i++) {
            if ((a >= b and a >= c and curra != 2) or
                (a > 0 and (currb == 2 or currc == 2))) {
                // If 'a' is maximum and it's streak is less than 2, or if
                // streak of 'b' or 'c' is 2, then 'a' will be the next
                // character.
                ans += 'a';
                a--;
                curra++;
                currb = 0;
                currc = 0;
            } else if ((b >= a and b >= c and currb != 2) or
                       (b > 0 and (currc == 2 or curra == 2))) {
                // If 'b' is maximum and it's streak is less than 2, or if
                // streak of 'a' or 'c' is 2, then 'b' will be the next
                // character.
                ans += 'b';
                b--;
                currb++;
                curra = 0;
                currc = 0;
            } else if ((c >= a and c >= b and currc != 2) or
                       (c > 0 and (curra == 2 or currb == 2))) {
                // If 'c' is maximum and it's streak is less than 2, or if
                // streak of 'a' or 'b' is 2, then 'c' will be the next
                // character.
                ans += 'c';
                c--;
                currc++;
                curra = 0;
                currb = 0;
            }
        }
        return ans;
    }
};
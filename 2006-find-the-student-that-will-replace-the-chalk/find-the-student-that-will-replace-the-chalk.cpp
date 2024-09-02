class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long total_chalk = 0;
        
        // Calculate the total amount of chalk needed in one full round.
        for (int c : chalk) {
            total_chalk += c;
        }
        
        // Reduce k by the total chalk modulo
        k %= total_chalk;
        
        // Identify the student who will run out of chalk
        for (int i = 0; i < chalk.size(); i++) {
            if (chalk[i] > k) {
                return i;
            }
            k -= chalk[i];
        }
        
        // This line theoretically should never be reached.
        return -1;
    }
};
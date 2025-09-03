class Solution {
public:
    const int base = 256;     // base for rolling hash (ASCII chars)
    const int mod = 1e9 + 7;  // large prime for avoiding overflow

    // Rabin-Karp substring search
    bool rabinKarp(string &text, string &pattern) {
        int n = text.size();
        int m = pattern.size();
        if(m > n) return false;

        long long hashText = 0, hashPattern = 0, power = 1;

        // Precompute base^(m-1) % mod
        for(int i = 0; i < m - 1; i++)
            power = (power * base) % mod;

        // Compute initial hashes
        for(int i = 0; i < m; i++) {
            hashText = (hashText * base + text[i]) % mod;
            hashPattern = (hashPattern * base + pattern[i]) % mod;
        }

        // Slide window
        for(int i = 0; i <= n - m; i++) {
            if(hashText == hashPattern) {
                if(text.substr(i, m) == pattern) return true; // check collision
            }

            // Roll hash (remove leftmost char, add next char)
            if(i < n - m) {
                hashText = (hashText - text[i] * power % mod + mod) % mod;
                hashText = (hashText * base + text[i + m]) % mod;
            }
        }
        return false;
    }

    int repeatedStringMatch(string a, string b) {
        string newstr = a;
        int repeat = 1;

        // Keep appending until long enough
        while(newstr.size() < b.size()) {
            newstr += a;
            repeat++;
        }

        // Check using Rabin-Karp
        if(rabinKarp(newstr, b)) return repeat;

        // Check one more repeat
        newstr += a;
        if(rabinKarp(newstr, b)) return repeat + 1;

        return -1;
    }
};

class Solution {
public:
    int distinctSubseqII(string s) {
        long long mod = 1e9 + 7;
        // Stores the count of distinct subsequences ending with each character 'a'-'z'
        vector<long long> last(26, 0);

        for (char c : s) {
            long long sum = 0;
            for (int i = 0; i < 26; ++i) {
                sum = (sum + last[i]) % mod;
            }
            // Add 1 for the subsequence consisting of just the character `c`
            last[c - 'a'] = (sum + 1) % mod;
        }

        long long ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = (ans + last[i]) % mod;
        }

        return ans;
    }
};

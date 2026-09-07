class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;
        vector<long long> endsWith(26, 0);
        long long total = 0;
        for (char ch : s) {
            int idx = ch - 'a';
            long long newVal = (1 + total) % MOD;
            total = ((total - endsWith[idx] + newVal) % MOD + MOD) % MOD;
            endsWith[idx] = newVal;
        }
        return (int) total;
    }
};
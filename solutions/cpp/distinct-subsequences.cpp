#include <string>
#include <vector>

class Solution {
public:
    int numDistinct(std::string s, std::string t) {
        int m = s.length();
        int n = t.length();
        
        // If s is shorter than t, t cannot be a subsequence of s
        if (m < n) return 0;
        
        // dp[j] stores the count of distinct subsequences for t[0...j-1]
        // Using unsigned long long to safely handle intermediate overflows
        std::vector<unsigned long long> dp(n + 1, 0);
        
        // Base case: An empty string t has 1 distinct subsequence in any prefix of s
        dp[0] = 1;
        
        // Iterate through each character of string s
        for (int i = 1; i <= m; ++i) {
            // Iterate backwards through t to use the 1D DP array optimization
            for (int j = n; j >= 1; --j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        
        return static_cast<int>(dp[n]);
    }
};

// Fast I/O optimization for LeetCode execution speed
auto speedup = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();
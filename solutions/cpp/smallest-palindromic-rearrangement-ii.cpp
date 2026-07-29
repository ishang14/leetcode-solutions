#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
private:
    const long long MAX_K = 1000005; // k <= 10^6, cap value to prevent overflow

    // Compute Combinations C(n, r) with a cap to prevent integer overflow
    long long getComb(int n, int r) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n - r) r = n - r; // Optimize using symmetry

        long long ans = 1;
        for (int i = 1; i <= r; ++i) {
            ans = ans * (n - i + 1) / i;
            if (ans >= MAX_K) return MAX_K; // Cap early
        }
        return ans;
    }

    // Calculate total distinct permutations for a multiset with specified frequencies
    long long countPermutations(const std::vector<int>& counts, int total_len) {
        long long ways = 1;
        int remaining = total_len;
        
        for (int c : counts) {
            if (c > 0) {
                ways *= getComb(remaining, c);
                if (ways >= MAX_K) return MAX_K; // Cap early
                remaining -= c;
            }
        }
        return ways;
    }

public:
    std::string smallestPalindrome(std::string s, int k) {
        std::vector<int> full_counts(26, 0);
        for (char ch : s) {
            full_counts[ch - 'a']++;
        }

        std::vector<int> half_counts(26, 0);
        std::string mid = "";
        int half_len = 0;

        // Distribute characters into the left half and center
        for (int i = 0; i < 26; ++i) {
            half_counts[i] = full_counts[i] / 2;
            half_len += half_counts[i];
            if (full_counts[i] % 2 != 0) {
                mid += (char)('a' + i);
            }
        }

        // Verify if total possible palindromic configurations can fulfill k
        long long total_ways = countPermutations(half_counts, half_len);
        if (total_ways < k) {
            return "";
        }

        std::string left_half = "";
        int remaining_len = half_len;

        // Construct the left half greedily character by character
        for (int i = 0; i < half_len; ++i) {
            for (int c = 0; c < 26; ++c) {
                if (half_counts[c] > 0) {
                    // Try placing character 'c' at the current position
                    half_counts[c]--;
                    long long ways = countPermutations(half_counts, remaining_len - 1);

                    if (k <= ways) {
                        // Character 'c' fits perfectly in this range block
                        left_half += (char)('a' + c);
                        remaining_len--;
                        break; // Move to the next position
                    } else {
                        // Skip this block of permutations and reduce k
                        k -= ways;
                        half_counts[c]++; // Restore state
                    }
                }
            }
        }

        // Reconstruct the full palindrome using: Left Half + Middle + Mirrored Left Half
        std::string right_half = left_half;
        std::reverse(right_half.begin(), right_half.end());
        
        return left_half + mid + right_half;
    }
};
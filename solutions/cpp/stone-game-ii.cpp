class Solution {
    vector<vector<int>> DP;

public:
    int solve(int i, int M, vector<int>& suffix) {
        if (i >= suffix.size()) {
            return 0;
        }
        if (DP[i][M] != -1) {
            return DP[i][M];
        }
        if (i + 2 * M >= suffix.size()) {
            return DP[i][M] = suffix[i];
        }
        int ans = 0;
        for (int x = 1; x <= 2 * M && x + i < suffix.size(); x++) {
            ans = max(ans, suffix[i] - solve(i + x, max(M, x), suffix));
        }
        return DP[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        DP.assign(n + 1, vector<int>(n + 1, -1));
        vector<int> suffix(n);
        suffix[n - 1] = piles.back();
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }
        return solve(0, 1, suffix);
    }
};
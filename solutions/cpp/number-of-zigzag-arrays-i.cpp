class Solution {
public:
    static const int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<long long> up(m, 1), down(m, 1);
        vector<long long> prefUp(m), prefDown(m);
        vector<long long> newUp(m), newDown(m);

        for (int len = 1; len < n; len++) {

            prefUp[0] = up[0];
            prefDown[0] = down[0];

            for (int i = 1; i < m; i++) {
                prefUp[i] = (prefUp[i - 1] + up[i]) % MOD;
                prefDown[i] = (prefDown[i - 1] + down[i]) % MOD;
            }

            long long totalDown = prefDown[m - 1];

            for (int y = 0; y < m; y++) {
                newDown[y] = (y ? prefUp[y - 1] : 0);
                newUp[y] =
                    (totalDown - prefDown[y] + MOD) % MOD;
            }

            swap(up, newUp);
            swap(down, newDown);
        }

        long long ans = 0;
        for (int i = 0; i < m; i++) {
            ans = (ans + up[i] + down[i]) % MOD;
        }

        return (int)ans;
    }
};
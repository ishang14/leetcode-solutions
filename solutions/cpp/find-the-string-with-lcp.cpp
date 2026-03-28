class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        vector<int> s(n, 0);
        int val = 1;

        for (int i = 0; i < n; i++) {
            if (s[i] > 0) {
                continue;
            }
            if (val > 26) {
                return "";
            }
            for (int j = i; j < n; j++) {
                if (lcp[i][j] > 0) {
                    s[j] = val;
                }
            }
            val++;
        }

        string res = "";
        for (int i = 0; i < n; i++) {
            res += char('a' + s[i] - 1);
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int new_val = 0;
                if (res[i] == res[j]) {
                    new_val = 1;
                    if (i + 1 < n && j + 1 < n) {
                        new_val += lcp[i + 1][j + 1];
                    }
                }
                if (lcp[i][j] != new_val) {
                    return "";
                }
            }
        }
        return res;
    }
};
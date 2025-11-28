class Solution {
    long dfs(const int node, const int par, const vector<vector<int>>& G, const vector<int>& values, const int K, int& ret) {
        long sum = values[node];
        for (const int neigh : G[node]) {
            if (neigh != par) {
                sum += dfs(neigh, node, G, values, K, ret);
            }
        }
        if (sum % K == 0) {
            ret += 1;
            return 0;
        }
        else {
            return sum;
        }
    }
public:
    int maxKDivisibleComponents(const int N, vector<vector<int>>& edges, const vector<int>& values, const int K) {
        vector<vector<int>> G(N);
        for (const auto& e : edges) {
            G[e[0]].emplace_back(e[1]);
            G[e[1]].emplace_back(e[0]);
        }
        int ret = 0;
        dfs(0, -1, G, values, K, ret);
        return ret;
    }
};
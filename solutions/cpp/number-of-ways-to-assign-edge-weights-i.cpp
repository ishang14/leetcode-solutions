class Solution {
public:
        int dfs(const unordered_map<int, vector<int>> &edges)
        {
                vector<pair<int, int>> stack;
                int m = 0;
                stack.push_back({ 1, 0 });
                while (!stack.empty()) {
                        const auto [i, c] = stack.back();
                        m = max(m, c);
                        stack.pop_back();
                        auto it = edges.find(i);
                        if (it == edges.end())
                                continue;
                        for (const auto &x : it->second)
                                stack.push_back({ x, c + 1});
                }
                return m;
        }

        int assignEdgeWeights(vector<vector<int>> &edges)
        {
                unordered_map<int, vector<int>> nodes;
                for (const auto &e : edges) {
                        if (e[0] < e[1])
                                nodes[e[0]].push_back(e[1]);
                        else
                                nodes[e[1]].push_back(e[0]);
                }
                const long mod = 1e9 + 7;
                const auto cnt = dfs(nodes);
                long acc = 1;
                for (int i = 0; i < cnt - 1; i++) {
                        acc *= 2;
                        acc %= mod;
                }
                return static_cast<int>(acc);
        }
};
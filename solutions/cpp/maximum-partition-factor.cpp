class Solution {
public:
    // DFS to color the conflict graph. 
    // u: current node, c: current color, n: number of points
    // dist: precomputed Manhattan distances, col: colors of nodes, lim: threshold T
    bool dfs(int u, int c, int n, vector<vector<int>>& dist, vector<int>& col, int lim) {
        col[u] = c;
        for (int v = 0; v < n; v++) {
            if (u == v) continue;

            // Conflict edge: distance less than current threshold
            if (dist[u][v] < lim) {
                if (col[v] == -1) {
                    // Color neighbor with opposite color
                    if (!dfs(v, 1 - c, n, dist, col, lim)) return false;
                } else if (col[v] == c) {
                    // Same color neighbor → not bipartite
                    return false;
                }
            }
        }
        return true;
    }

    // Check if conflict graph with threshold lim is bipartite
    bool check(vector<vector<int>>& dist, int n, int lim) {
        vector<int> col(n, -1);  // -1 = uncolored
        for (int u = 0; u < n; u++) {
            if (col[u] == -1) {
                if (!dfs(u, 0, n, dist, col, lim)) return false;
            }
        }
        return true;
    }

    int maxPartitionFactor(vector<vector<int>>& v) {
        int n = v.size();

        // Edge case: n = 2 → both groups have 1 point → partition factor = 0
        if (n == 2) return 0;

        // Precompute Manhattan distances between all pairs
        vector<vector<int>> dist(n, vector<int>(n, 0));
        int r = 0; // max possible distance
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                dist[i][j] = dist[j][i] = abs(v[i][0] - v[j][0]) + abs(v[i][1] - v[j][1]);
                r = max(r, dist[i][j]);
            }
        }

        // Binary search to find maximum threshold T where conflict graph is bipartite
        int l = 0, ans = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (check(dist, n, m)) {
                ans = m;    // feasible → try larger threshold
                l = m + 1;
            } else {
                r = m - 1;  // not feasible → try smaller
            }
        }
        return ans;
    }
};
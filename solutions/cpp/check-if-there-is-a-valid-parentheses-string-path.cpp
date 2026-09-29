class Solution {
public:
    int8_t memo[101][101][201];

    bool dfs(int x, int y, int state, int n, int m, vector<vector<char>>& grid) {
        if (memo[x][y][state] != -1) return memo[x][y][state];

        if (x == n - 1 && y == m - 1) {
            if (state == 0) return true;
            return false;
        }

        bool res = false;
        if (x + 1 < n) {
            int nextState = state + (grid[x + 1][y] == ')' ? -1 : 1);
            if (nextState >= 0) res |= dfs(x + 1, y, nextState, n, m, grid);
        }

        if (y + 1 < m) {
            int nextState = state + (grid[x][y + 1] == ')' ? -1 : 1);
            if (nextState >= 0) res |= dfs(x, y + 1, nextState, n, m, grid);
        }

        memo[x][y][state] = res;
        return res;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        if (grid[0][0] == ')') return false;

        int n = grid.size();
        int m = grid[0].size();

        memset(memo, -1, sizeof(memo));
        return dfs(0, 0, 1, n, m, grid);
    }
};
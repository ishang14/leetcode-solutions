//translated using AI
class Solution {
public:
    vector<int> parent, rank;

    int minScore(int n, vector<vector<int>>& roads) {
        parent.resize(n + 1);
        rank.assign(n + 1, 0);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        for (auto &road : roads)
            unite(road[0], road[1]);

        int root = find(1);
        int ans = INT_MAX;

        for (auto &road : roads) {
            if (find(road[0]) == root)
                ans = min(ans, road[2]);
        }

        return ans;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb) return;

        if (rank[pa] < rank[pb])
            parent[pa] = pb;
        else if (rank[pa] > rank[pb])
            parent[pb] = pa;
        else {
            parent[pb] = pa;
            rank[pa]++;
        }
    }
};
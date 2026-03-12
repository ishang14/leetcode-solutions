class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        fill(rk, rk + n, 0);
        fill(st, st + n, 200000);
        iota(par, par + n, 0);

        int cmp = n;

        for (auto &p: edges) {
            if (p[3] == 1) {
                if (!con(p[0], p[1], p[2])) {
                    return -1;
                } else {
                    --cmp;
                }
            }
        }

        rt.reset();

        int ans = 200000;
        
        for (int i = 0; i < n; ++i) {
            int ri = findR(i);
            ans = min(ans, st[ri]);
            rt.set(ri);
        }

        priority_queue<array<int, 3>> pq;
        for (auto &p: edges) {
            if (p[3] == 0) {
                int ra = findR(p[0]), rb = findR(p[1]);
                if (ra != rb) {
                    pq.emplace(array<int, 3>{p[2], ra, rb});
                }
            }
        }

        vector<int> add;

        while (!pq.empty()) {
            auto [s, a, b] = pq.top(); pq.pop();

            if (con(a, b, s)) {
                add.push_back(s);
                --cmp;
            }
        }

        //cout << ans << endl;

        if (cmp > 1) return -1;
        else {
            int l = add.size();
            for (int i = l - 1; i >= 0; --i) {
                //cout << add[i] << endl;
                if (i >= max(l - k, 0)) ans = min(ans, add[i] * 2);
                else ans = min(ans, add[i]);
            }
            return ans;
        }
    }
private:
    inline static int par[100000] = {0};
    inline static int rk[100000] = {0};
    inline static int st[100000] = {100000};
    inline static bitset<100000> rt;
    
    int findR(int a) {
        return par[a] = (par[a] == a) ? a : findR(par[a]);
    }

    bool con(int a, int b, int s) {
        int ra = findR(a), rb = findR(b);
        if (ra == rb) return false;

        if (rk[ra] < rk[rb]) {
            swap(ra, rb);
        }

        if (rk[ra] == rk[rb]) {
            ++rk[ra];
        } 

        par[rb] = ra;
        st[ra] = min({st[ra], st[rb], s});

        return true;
    }
};
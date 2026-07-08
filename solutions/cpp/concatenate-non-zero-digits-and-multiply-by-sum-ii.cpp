
class Solution {
public:
    static const int MOD = 1000000007;

    struct Node {
        long long val;
        int len;
    };

    vector<Node> seg;
    vector<long long> pw;
    vector<int> digits;

    Node merge(Node a, Node b) {
        return {(a.val * pw[b.len] + b.val) % MOD, a.len + b.len};
    }

    void build(int idx, int l, int r) {
        if (l == r) {
            seg[idx] = {digits[l], 1};
            return;
        }
        int mid = (l + r) / 2;
        build(idx * 2, l, mid);
        build(idx * 2 + 1, mid + 1, r);
        seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return seg[idx];
        int mid = (l + r) / 2;
        if (qr <= mid) return query(idx * 2, l, mid, ql, qr);
        if (ql > mid) return query(idx * 2 + 1, mid + 1, r, ql, qr);
        return merge(query(idx * 2, l, mid, ql, qr),
                     query(idx * 2 + 1, mid + 1, r, ql, qr));
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + (s[i] - '0');

        vector<int> id(n, -1);
        vector<int> pos;

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                id[i] = digits.size();
                digits.push_back(s[i] - '0');
                pos.push_back(i);
            }
        }

        int m = digits.size();

        pw.assign(m + 1, 1);
        for (int i = 1; i <= m; i++)
            pw[i] = pw[i - 1] * 10 % MOD;

        if (m) {
            seg.resize(4 * m + 5);
            build(1, 0, m - 1);
        }

        vector<int> nextNZ(n + 1, n), prevNZ(n, -1);

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != '0')
                nextNZ[i] = i;
            else
                nextNZ[i] = nextNZ[i + 1];
        }

        int last = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') last = i;
            prevNZ[i] = last;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            long long sum = pref[r + 1] - pref[l];

            int first = nextNZ[l];
            int lastPos = prevNZ[r];

            if (first > r || lastPos < l) {
                ans.push_back(0);
                continue;
            }

            int L = id[first];
            int R = id[lastPos];

            Node cur = query(1, 0, m - 1, L, R);

            ans.push_back(cur.val * (sum % MOD) % MOD);
        }

        return ans;
    }
};

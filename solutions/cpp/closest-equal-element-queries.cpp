class Solution {
public:
    int minDistance(vector<int>& v, int idx, int n) {
        if (v.size() == 1)
            return -1;

        auto it = lower_bound(v.begin(), v.end(), idx);
        int ans = INT_MAX;

        int pos = it - v.begin();

        int next = (pos + 1) % v.size();
        int prev = (pos - 1 + v.size()) % v.size();

        int d1 = abs(v[next] - idx);
        int d2 = abs(v[prev] - idx);

        ans = min(ans, min(d1, n - d1));
        ans = min(ans, min(d2, n - d2));

        return ans;
    }

    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (int idx : queries) {
            if (idx >= 0 && idx < n) {
                int val = nums[idx];
                ans.push_back(minDistance(mp[val], idx, n));
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};
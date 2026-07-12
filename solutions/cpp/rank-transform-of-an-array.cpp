class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) return {};
        // Copy and sort
        vector<int> b = arr;
        sort(b.begin(), b.end());

        // Deduplicate
        b.erase(unique(b.begin(), b.end()), b.end());

        // Map each unique value to its rank
        unordered_map<int,int> mp;
        mp.reserve(b.size()); // avoid rehashing
        for (int i = 0; i < (int)b.size(); i++) {
            mp[b[i]] = i + 1;  // rank starts at 1
        }

        // Build result directly with pre-sized vector
        vector<int> ans(arr.size());
        for (int i = 0; i < (int)arr.size(); i++) {
            ans[i] = mp[arr[i]];
        }

        return ans;
    }
};
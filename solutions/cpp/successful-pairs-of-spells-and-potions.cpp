class Solution {
public:
    int check(vector<int>& p, int spell, long long success, int n1) {
        int n = p.size();
        int low = 0, high = n - 1;

        if ((long long)p[high] * spell < success) return n1;
        if ((long long)p[low] * spell >= success) return 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if ((long long)p[mid] * spell >= success)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        vector<int> ans;
        sort(potions.begin(), potions.end());
        for (int i = 0; i < n; i++) {
            int ind = check(potions, spells[i], success, potions.size());
            ans.push_back(potions.size() - ind);
        }
        return ans;
    }
};
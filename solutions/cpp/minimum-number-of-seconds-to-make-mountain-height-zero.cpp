class Solution {
public:
    long long maxUnits(long long T, int t) {
        long long val = (2 * T) / t;
        long long k = (sqrt(1 + 4 * val) - 1) / 2;
        return k;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 1, right = 1e18, ans = right;
        while (left <= right) {
            long long mid = (left + right) / 2;
            long long removed = 0;
            for (int t : workerTimes) {
                removed += maxUnits(mid, t);
                if (removed >= mountainHeight) break;
            }
            if (removed >= mountainHeight) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
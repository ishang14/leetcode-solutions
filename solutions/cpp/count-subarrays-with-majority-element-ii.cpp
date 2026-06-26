class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        map<long long, long long> freq;
        long long sum = 0;
        int n = nums.size();
        long long tillThisPoint = 0;

        freq[0] = 1;

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            if (nums[i] == target) {
                // Query range expands
                tillThisPoint += freq[sum];
                sum++;
            } else {
                // Query range shrinks
                sum--;
                tillThisPoint -= freq[sum];
            }

            // Record current prefix balance
            freq[sum]++;

            // Count valid subarrays ending here
            ans += tillThisPoint;
        }

        return ans;
    }
};
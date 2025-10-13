class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int target = 0;
        vector<vector<int>> ans;

        for (int i = 0; i < n - 2;
             i++) { // Ensure enough elements for a triplet
            if (i > 0 && nums[i] == nums[i - 1]) // Skip duplicates for i
                continue;

            int low = i + 1;
            int high = n - 1;

            while (low < high) {
                int sum = nums[i] + nums[low] + nums[high];

                if (sum > target) {
                    high--;
                } else if (sum < target) {
                    low++;
                } else {
                    ans.push_back({nums[i], nums[low], nums[high]});
                    low++;
                    high--;
                    // Skip duplicates for low
                    while (low < high && nums[low] == nums[low - 1])
                        low++;
                    // Skip duplicates for high
                    while (low < high && nums[high] == nums[high + 1])
                        high--;
                }
            }
        }

        return ans;
    }
};
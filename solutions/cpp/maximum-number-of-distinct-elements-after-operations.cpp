class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        nums[0] -= k;
        int n = nums.size(), maxi = nums[0], ans = 1;
        for(int i = 1;i<n;i++){
            nums[i] = max(min(nums[i-1] + 1, nums[i] + k), nums[i] - k);
            if(nums[i] != nums[i-1])
                ans++;
        }
        return ans;
    }
};
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long f = 0, n = nums.size();
        long numSum = accumulate(nums.begin(), nums.end(), 0);

        for (int i=0; i<n; i++){
            f += (long)i * nums[i];
        }
        long maxSum = f;
        for (int i= n - 1; i>0; i--) {
            f += numSum - (long)n * nums[i];
            maxSum = max(maxSum, f);
        }
        return (int)maxSum;
    }
};
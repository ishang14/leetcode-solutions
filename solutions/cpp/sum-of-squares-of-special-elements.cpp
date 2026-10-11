class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        // i = position, counting from 1
        for (int i = 1; i <= n; i++) {
            if (n % i == 0)
                ans += nums[i - 1] * nums[i - 1];
        }

        return ans;
    }
};
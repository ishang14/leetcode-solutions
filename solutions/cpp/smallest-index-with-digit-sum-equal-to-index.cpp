class Solution {
public:
    int calculate(int n) {
        int s = 0;
        while (n) {
            int d = n % 10;
            n = n / 10;
            s += d;
        }
        return s;
    }
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int sum = calculate(nums[i]);
            if (sum == i)
                return i;
        }
        return -1;
    }
};
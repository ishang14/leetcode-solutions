class Solution {
public:
    int gcd(int a, int b){
        while(b != 0){
            int temp = a%b;
            a = b;
            b = temp;
        }
        return a;
    }

public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int a = nums[0];
        int b = nums[n-1];

        int ans = gcd(a, b);

        return ans;
    }
};
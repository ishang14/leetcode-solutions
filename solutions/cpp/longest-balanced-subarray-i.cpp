bitset<100001> freq;
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        const int n = nums.size();
        int res = 0;
        for(int i = 0; i < n; ++i){
            int diff = 0;
            for(int j = i; j < n; ++j){
                int num = nums[j];
                if(!freq.test(num)) diff += (num & 1) ? 1 : -1;
                freq.set(num);
                if(!diff) res = max(res , j - i + 1);
            }
            freq.reset();
        }
        return res;
    }
};
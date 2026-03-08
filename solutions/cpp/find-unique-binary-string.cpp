class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans{""};
        for(size_t i = 0; i < nums.size(); ++i)
            ans += (nums[i][i] == '0' ? '1' : '0');
        return ans;
    }
};
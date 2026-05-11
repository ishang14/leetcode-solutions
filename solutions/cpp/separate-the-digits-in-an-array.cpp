class Solution {
public:
    vector<int> revNum(int num){
        vector<int> arr;
        while(num>0){
            int n = num%10;
            num/=10;
            arr.push_back(n);
        }
        reverse(arr.begin(), arr.end());

        return arr;
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++){
            vector<int> arr = revNum(nums[i]);
            for(int j = 0; j<arr.size(); j++){
                ans.push_back(arr[j]);
            }
        }
        return ans;
    }
};
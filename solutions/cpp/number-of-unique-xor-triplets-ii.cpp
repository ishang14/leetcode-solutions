class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(1<<11);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                f[nums[i]^nums[j]]++;
            }
        }

        int res = 0;
        for(int i=0; i<(1<<11); i++){
            bool ok = false;
            for(auto x: nums){
                if(f[i^x]) {
                    ok = true;
                    break;
                }
            }
            if(ok) res++;
        }

        return res;
    }
};
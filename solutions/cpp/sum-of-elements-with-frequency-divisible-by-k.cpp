class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        //<key,count>
        int sum=0;

        for(int i:nums)
            {
                mp[i]+=1;
            }

        for(auto it:mp)
            {
                if(it.second%k==0)
                    sum+=it.first*it.second;
            }
        return sum;
    }
};
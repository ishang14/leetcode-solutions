class Solution {
public:

    void sol(vector<int>& v, vector<vector<int>>& ans,vector<int>& temp,int curr,int n)
    {
        ans.push_back(temp);

        for(int i=curr;i<n;i++)
        {
            if(i>curr && v[i]==v[i-1])
            continue;

            temp.push_back(v[i]);
            sol(v,ans,temp,i+1,n);
            temp.pop_back();
        }
    }
    

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        sort(nums.begin(),nums.end());

        sol(nums,ans,temp,0,n);

        return ans;
    }
};
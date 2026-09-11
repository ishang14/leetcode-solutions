class Solution {
public:

    void sol(vector<int>& v,int i,int n,vector<vector<int>>& ans,vector<int>& temp)
    {

        if(i>n)
        return;

        if(i==n)
        {
            ans.push_back(temp);
            return;
        }

        temp.push_back(v[i]);
        sol(v,i+1,n,ans,temp);
        temp.pop_back();

        sol(v,i+1,n,ans,temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> temp;

        sol(nums,0,n,ans,temp);

        return ans;
    }
};
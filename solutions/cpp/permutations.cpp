class Solution {
public:

    void sol(vector<int>& v,vector<int>& perm,vector<vector<int>>& ans,vector<bool>& marked){

        if(v.size()==perm.size())
        {
            ans.push_back(perm);
            return;
        }

        for(int i=0;i<v.size();i++)
        {
            if(marked[i]==true)
            continue;

            perm.push_back(v[i]);
            marked[i]=true;
            sol(v,perm,ans,marked);
            perm.pop_back();
            marked[i]=false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n=nums.size();
        vector<bool> marked(n, false);

        sol(nums,temp,ans,marked);

        return ans;
    }
};
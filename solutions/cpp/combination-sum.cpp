class Solution {
public:

    void helper(vector<int>& v,int target,int i,int n,int sum,vector<vector<int>> &ans,vector<int> &temp){

        if(sum==target)
        {
        ans.push_back(temp);
        return;
        }

        if(i==n || sum>target)
        {
            return;
        }

        temp.push_back(v[i]);
        helper(v,target,i,n,sum+v[i],ans,temp);
        temp.pop_back();

        helper(v,target,i+1,n,sum,ans,temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(candidates,target,0,candidates.size(),0,ans,temp);

        return ans;
    }
};
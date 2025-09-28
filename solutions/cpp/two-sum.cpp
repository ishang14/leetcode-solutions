class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {

    vector<int> ans;

    unordered_map<int,int> mp;

    for(int i=0;i<arr.size();i++)
    {
        int a=arr[i];
        int b=target-a;

        if(mp.find(b) != mp.end())
        {
            ans.push_back(mp[b]);
            ans.push_back(i);
            break;
        }
        mp[a]=i;
    }

    return ans;
    }
};
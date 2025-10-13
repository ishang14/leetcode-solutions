class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1=INT_MIN,ele2=INT_MIN;
        int cnt1=0,cnt2=0;

        for(int i:nums)
        {
            if(cnt1==0 && i!=ele2)
            {
                cnt1=1;
                ele1=i;
            }
            else if(cnt2==0 && i!=ele1)
            {
                cnt2=1;
                ele2=i;
            }
            else if(i==ele1)
            {
                cnt1++;
            }
            else if(i==ele2)
            {
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ans;
        cnt1=0,cnt2=0;

        for(int i:nums){
            if(i==ele1)
            cnt1++;
            else if(i==ele2)
            cnt2++;
        }
        if(cnt1>nums.size()/3)
        ans.push_back(ele1);
        if(cnt2>nums.size()/3)
        ans.push_back(ele2);

        return ans;
    }
};
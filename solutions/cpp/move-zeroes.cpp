class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int firstZeroLocation=-1;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                firstZeroLocation=i;
                break;
            }
        }

        if(firstZeroLocation!=-1)
        {
        for(int i=firstZeroLocation+1;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                swap(nums[firstZeroLocation],nums[i]);
                firstZeroLocation++;
            }
        }
        }

    }
};
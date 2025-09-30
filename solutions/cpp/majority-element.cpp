class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int hypotheticalMajorityElement;
        int count = 0;

        for (int i : nums) {
            if (count == 0) {
                hypotheticalMajorityElement = i;
            }
            if (i == hypotheticalMajorityElement) {
                count++;
            } else {
                count--;
            }
        }

        count = 0;

        for (int i : nums) {
            if (i == hypotheticalMajorityElement)
                count++;
        }

        if (count > nums.size() / 2) {
            return hypotheticalMajorityElement;
        }
        else {
            return -1;
        }
    }
};
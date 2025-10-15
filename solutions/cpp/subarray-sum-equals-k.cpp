class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumMap;  // prefix_sum: frequency
        sumMap[0] = 1;                   // empty prefix before first element
        
        int prefix_sum = 0;
        int count = 0;
        
        for (int num : nums) {
            prefix_sum += num;
            
            // If (prefix_sum - k) exists, add its frequency to result
            if (sumMap.find(prefix_sum - k) != sumMap.end()) {
                count += sumMap[prefix_sum - k];
            }
            
            // Update frequency of current prefix sum
            sumMap[prefix_sum]++;
        }
        
        return count;
    }
};
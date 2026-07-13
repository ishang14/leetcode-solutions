class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        long long id = 1;
        while(id < 10) {
            long long tmp = id, ct = id+1;
            while(tmp <= high) {
                if(tmp >= low) ans.push_back(tmp);
                if(ct > 9) break;
                tmp = tmp * 10 + ct;
                ct++;
            }
            id++;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
class Solution {
public:
    int maxOperations(string s) {
        //0001111
        //
        int n = s.size();
        int count = 0,ans =0;
        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                count++;
            }
            if(s[i] == '1' && s[i+1] == '0'){
                ans += count;
            }
        }
        return ans;
    }
};
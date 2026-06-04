class Solution {
public:
    int check(int n) {
        string s = to_string(n);
        
        int cnt = 0;
        for (int i = 1; i < s.size() - 1; i++) {
            cnt += ((s[i] > s[i - 1] && s[i] > s[i + 1]) || (s[i] < s[i - 1] && s[i] < s[i + 1]));
        }
        
        return cnt;
    }

    int totalWaviness(int a, int b) {
        long long ans = 0;
        for (int i = a; i <= b; i++) {
            ans += (check(i));
        }

        return ans;
    }
};
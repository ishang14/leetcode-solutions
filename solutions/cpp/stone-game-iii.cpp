class Solution {
public:
    string stoneGameIII(vector<int>& st) {
        int n=st.size();
        vector<int>dp(n+3,0);

        dp[n-1]=st[n-1];

        for(int i=n-1;i>=0;i--){
            dp[i]=max(
                {st[i]-dp[i+1],
                (i+1<n?st[i]+st[i+1]-dp[i+2]:INT_MIN),
                (i+2<n ?st[i]+st[i+1]+st[i+2]-dp[i+3]:INT_MIN)}
            );
        }

        if(dp[0]>0)return "Alice";
        else if(dp[0]<0)return "Bob";
        return "Tie";
    }
};
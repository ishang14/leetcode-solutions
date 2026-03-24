class Solution {
public:
    int MOD  = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>res(n,vector<int>(m));
        vector<long long>pref(n*m);
        vector<long long>suf(n*m);

        auto get = [&](int i,int j){ return i*m + j; };

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                int idx = get(i,j);
                pref[idx] = idx>0 ? (pref[idx-1]*grid[i][j])%MOD : grid[i][j]%MOD;
            }

        for(int i=n-1;i>=0;i--)
            for(int j=m-1;j>=0;j--){
                int idx = get(i,j);
                suf[idx] = idx<n*m-1 ? (suf[idx+1]*grid[i][j])%MOD : grid[i][j]%MOD;
            }

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                int idx = get(i,j);
                long long l = idx>0 ? pref[idx-1] : 1;
                long long r = idx<n*m-1 ? suf[idx+1] : 1;
                res[i][j] = (l*r)%MOD;
            }
        return res;
    }
};
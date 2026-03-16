class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> d1(n+1, vector<int>(m+1));
        vector<vector<int>> d2(n+1, vector<int>(m+2));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                d1[i+1][j+1] = grid[i][j] + d1[i][j];
                d2[i+1][j] = grid[i][j] + d2[i][j+1];
            }
        }

        set<int> st;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                st.insert(grid[i][j]);

                for(int k=1;i-k>=0 && i+k<n && j-k>=0 && j+k<m;k++){

                    int sum = 0;

                    sum += d1[i+1][j+k+1] - d1[i-k][j];
                    sum += d2[i+1][j-k] - d2[i-k][j+1];
                    sum += d1[i+k+1][j+1] - d1[i][j-k];
                    sum += d2[i+k+1][j] - d2[i][j+k+1];

                    sum -= grid[i-k][j];
                    sum -= grid[i][j+k];
                    sum -= grid[i+k][j];
                    sum -= grid[i][j-k];

                    st.insert(sum);
                }
            }
        }

        vector<int> res(st.begin(), st.end());

        sort(res.rbegin(), res.rend());

        if(res.size() > 3) res.resize(3);

        return res;
    }
};
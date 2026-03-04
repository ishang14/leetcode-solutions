class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;
        
        for (int i = 0; i < m; i++) {
            int rowones = 0;
            int colidx = -1;
            
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    rowones++;
                    colidx = j;
                }
            }
            
            if (rowones == 1) {
                int colones = 0;
                for (int k = 0; k < m; k++) {
                    if (mat[k][colidx] == 1) {
                        colones++;
                    }
                }
                if (colones == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
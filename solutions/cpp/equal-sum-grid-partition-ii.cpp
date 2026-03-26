class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int col = grid[0].size();

        long long total = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<col;j++){
                total += grid[i][j];
            }
        }

        unordered_map<long long,int> topFreq, bottomFreq, leftFreq, rightFreq;

        for(int i=0;i<n;i++){
            for(int j=0;j<col;j++){
                bottomFreq[grid[i][j]]++;
            }
        }

        auto check = [&](long long val,int r1,int r2,int c1,int c2,unordered_map<long long,int>& mp){
            if(val<=0 || mp.find(val)==mp.end()) return false;

            int h = r2-r1+1;
            int w = c2-c1+1;

            if(h==1 && w>1) return (long long)grid[r1][c1]==val || (long long)grid[r1][c2]==val;
            if(w==1 && h>1) return (long long)grid[r1][c1]==val || (long long)grid[r2][c1]==val;
            if(h==1 && w==1) return (long long)grid[r1][c1]==val;

            return true;
        };

        long long topSum = 0;

        for(int i=0;i<n-1;i++){
            for(int j=0;j<col;j++){
                long long v = grid[i][j];
                topSum += v;
                topFreq[v]++;
                if(--bottomFreq[v]==0) bottomFreq.erase(v);
            }

            long long bottomSum = total - topSum;

            if(topSum == bottomSum) return true;

            long long removetop = 2*topSum - total;
            if(check(removetop,0,i,0,col-1,topFreq)) return true;

            long long removebot = total - 2*topSum;
            if(check(removebot,i+1,n-1,0,col-1,bottomFreq)) return true;
        }

        bottomFreq.clear();
        for(int i=0;i<n;i++){
            for(int j=0;j<col;j++){
                bottomFreq[grid[i][j]]++;
            }
        }

        long long leftSum = 0;

        for(int j=0;j<col-1;j++){
            for(int i=0;i<n;i++){
                long long v = grid[i][j];
                leftSum += v;
                leftFreq[v]++;
                if(--bottomFreq[v]==0) bottomFreq.erase(v);
            }

            long long rightSum = total - leftSum;

            if(leftSum == rightSum) return true;

            long long removeleft = 2*leftSum - total;
            if(check(removeleft,0,n-1,0,j,leftFreq)) return true;

            long long removeright = total - 2*leftSum;
            if(check(removeright,0,n-1,j+1,col-1,bottomFreq)) return true;
        }

        return false;
    }
};
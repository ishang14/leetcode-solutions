class Solution {
public:
    int mod = 1e9+7;
    vector<vector<int>> matmul(vector<vector<int>> A, vector<vector<int>> B) {
        int n = (int)A.size();
        int m = (int)A[0].size();
        int p = (int)B[0].size();
        vector<vector<int>> C(n, vector<int>(p, 0));
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < m; ++k) {
                if (A[i][k] == 0) continue;
                int aik = A[i][k]%mod;
                for (int j = 0; j < p; ++j) {
                    C[i][j] = (C[i][j] + 1LL * aik * B[k][j]) % mod;
                }
            }
        }
        return C;
    }
    vector<vector<int>> mat_pow(vector<vector<int>> a, int x) {
        int n = a.size();
        vector<vector<int>> res(n, vector<int> (n, 0));
        for(int i=0; i<n; i++) res[i][i] = 1;
        while(x > 0) {
            if(x & 1) res = matmul(res, a);
            a = matmul(a, a);
            x>>=1;
        }
        return res;
    }
    vector<vector<int>> mat_add(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> C(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            C[i][j] = (A[i][j] + B[i][j]) % mod;
        }
    }
    return C;
}

    void print(const vector<vector<int>>& mat) {
    for (int i = 0; i < mat.size(); ++i) {
        for (int j = 0; j < mat[i].size(); ++j) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
    
    int zigZagArrays(int n, int l, int r) {
        int s = (r-l+1);
        vector<vector<int>> dec(1, vector<int>(s, 1)), inc(1, vector<int>(s, 1));
        vector<vector<int>> m1(s, vector<int> (s, 0)), m2(s, vector<int> (s, 0));

        for(int i=0; i<s; i++) {
            for(int j=0; j<i; j++) {
                m1[i][j] = 1;
            }
        }

        for(int i=0; i<s; i++) {
            for(int j=i+1; j<s; j++) {
                m2[i][j] = 1;
            }
        }

        // print(inc);
        // print(dec);
        
        // print(m1);
        // print(m2);

        vector<vector<int>> m12 = matmul(m1, m2);
        vector<vector<int>> m21 = matmul(m2, m1);
        vector<vector<int>> ndec, ninc;
        // print(m12);
        // print(m21);
        
        if((n-1)%2 == 0) {
            ndec = matmul(dec, mat_pow(m12, (n-1)/2));
            ninc = matmul(inc, mat_pow(m21, (n-1)/2));
        }
        else {
            ndec = matmul(matmul(inc, mat_pow(m21, (n-1)/2)), m2);
            ninc = matmul(matmul(dec, mat_pow(m12, (n-1)/2)), m1);
        }

        // print(ndec);
        // print(ninc);
        
        int ans = 0;
        for(int i=0; i<ndec[0].size(); i++) {
            ans = (ans + ndec[0][i])%mod;
            ans = (ans + ninc[0][i])%mod;
        }
        return ans;
    }
};
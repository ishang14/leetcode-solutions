class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> m;
        for(int i=0;i<A.size();i++){
            m[A[i]]=i;
        }
        int n=A.size();
        vector<int> pre(n);
        for(int i=0;i<n;i++){
            int idx=m[B[i]];
            if(idx<=i) pre[i]++;
            if(idx>i) pre[idx]++;
        }
        for(int i=1;i<n;i++) pre[i]=pre[i]+pre[i-1];
        return pre;
    }
};
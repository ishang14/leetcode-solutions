class Solution {
public:
    int fib(int n) {

        if(n==0 || n==1)
        return n;

        int second_prev=0,ans=0,prev=1;

        for(int i=2;i<=n;i++)
        {
            ans=second_prev+prev;
            second_prev=prev;
            prev=ans;
        }
        return ans;
    }
};
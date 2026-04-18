class Solution {
public:
    int mirrorDistance(int n) {
        int y=n;
        int s=0;
        while(n!=0){
            s=s*10+(n%10);
            n=n/10;
        }
        return abs(s-y);
    }
};
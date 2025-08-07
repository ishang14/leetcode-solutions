class Solution {
public:
    bool isPalindrome(int x) {
        if(x>=0)
        {
            int temp=x;
            int rev=0;
            while(x>0)
            {
                if(rev>INT_MAX/10)
                return false;
                rev=rev*10+x%10;
                x/=10;
            }
            if(temp==rev)
            return true;
        }
        return false;
    }
};
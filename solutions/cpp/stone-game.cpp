class Solution {
public:
    bool stoneGame(vector<int>& piles) 
    {
        int a = 0;
        int b = 0;
        int l = 0;
        int r = piles.size()-1;
        int cnt = 0;
        while(l<=r)
        {
            if(cnt%2==0)
            {
                if(piles[l]>piles[r])
                {
                    a += piles[l];
                    l++;
                }
                else
                {
                    a += piles[r];
                    r--;
                }
            }
            else
            {
                if(piles[l]>piles[r])
                {
                    b += piles[r];
                    r--;
                }
                else
                {
                    a += piles[l];
                    l++;
                }
            }
            cnt++;
        }
        return a>b ? true : false;
    }
//please upvote...
};
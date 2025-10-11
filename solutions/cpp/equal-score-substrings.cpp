class Solution {
public:

    int calcScore(string s)
    {
        int n=s.length();
        int score=0;
        for(int i=0;i<n;i++)
            {
                score+=(int)(s[i]-96);
            }
        return score;
    }
    
    bool scoreBalance(string s) {
        int n=s.length();
        for(int i=1;i<n;i++)
            {
                string s1=s.substr(0,i);
                string s2=s.substr(i);

                int scoreS1=calcScore(s1);
                int scoreS2=calcScore(s2);

                if(scoreS1==scoreS2)
                    return true;
            }
        return false;
    }
};
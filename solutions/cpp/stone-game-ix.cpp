class Solution {
public:
    bool stoneGameIX(vector<int>& stones){

        int a=0,b=0,c=0;
        
        for(int i=0;i<stones.size();i++){
            int v=stones[i]%3;
            if (v==0) a++;
            else if(v==1) b++;
            else c++;
        }
        
        if(a%2==0) return b>0 && c>0;
        else return abs(b-c)>2;
    }
};
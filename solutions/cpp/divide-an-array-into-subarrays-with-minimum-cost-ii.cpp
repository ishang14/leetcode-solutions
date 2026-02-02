class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        const long long INF = (1LL<<60);

        int t = k - 2;

        using P = pair<int,int>;
        priority_queue<P> S; // max heap (t smallest)
        priority_queue<P, vector<P>, greater<P>> B; // min heap (rest)

        vector<char> dead(n, 0), pos(n, 0); // pos: 1=S, 2=B
        long long sumS = 0;
        int cntS = 0, cntB = 0;

        auto pruneS = [&](){ while(!S.empty() && dead[S.top().second]) S.pop(); };
        auto pruneB = [&](){ while(!B.empty() && dead[B.top().second]) B.pop(); };

        auto toB = [&](){
            pruneS();
            auto [v,i]=S.top(); S.pop();
            sumS -= v; cntS--;
            B.push({v,i}); cntB++; pos[i]=2;
        };
        auto toS = [&](){
            pruneB();
            auto [v,i]=B.top(); B.pop();
            cntB--;
            S.push({v,i}); cntS++; sumS += v; pos[i]=1;
        };

        auto fix = [&](){
            pruneS(); pruneB();
            if(cntS && cntB && !S.empty() && !B.empty() && S.top().first > B.top().first){
                auto x=S.top(); S.pop();
                auto y=B.top(); B.pop();
                sumS -= x.first; sumS += y.first;
                S.push(y); B.push(x);
                pos[x.second]=2; pos[y.second]=1;
            }
        };

        auto reb = [&](){
            pruneS(); pruneB(); fix();
            while(cntS > t) toB();
            while(cntS < t && cntB) toS();
            pruneS(); pruneB(); fix();
        };

        auto add = [&](int i){
            dead[i]=0;
            int v=nums[i];
            if(cntS < t){
                S.push({v,i}); pos[i]=1; cntS++; sumS+=v;
            }else{
                pruneS();
                if(t>0 && !S.empty() && v < S.top().first){
                    auto out=S.top(); S.pop();
                    sumS -= out.first; cntS--;
                    B.push(out); cntB++; pos[out.second]=2;
                    S.push({v,i}); pos[i]=1; cntS++; sumS+=v;
                }else{
                    B.push({v,i}); pos[i]=2; cntB++;
                }
            }
            reb();
        };

        auto rem = [&](int i){
            if(pos[i]==0) return;
            dead[i]=1;
            if(pos[i]==1){ sumS -= nums[i]; cntS--; }
            else cntB--;
            pos[i]=0;
            reb();
        };

        // i1=1 => window [2..1+dist]
        for(int idx=2; idx<=min(n-1,1+dist); idx++) add(idx);

        long long ans=INF;
        for(int i1=1; i1<=n-2; i1++){
            int winL=i1+1, winR=min(n-1,i1+dist);
            if(winR-winL+1 < t) break;
            ans=min(ans,(long long)nums[0]+nums[i1]+sumS);
            rem(i1+1);
            int in=i1+dist+1;
            if(in<=n-1) add(in);
        }
        return ans>=INF?-1:ans;
    }
};
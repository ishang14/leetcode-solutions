#define ll long long
class Solution {
public:
    const int mod = 1e9+7;

    ll modpow(ll a, ll b){
        ll res = 1;
        while(b){
            if(b&1) res = res*a % mod;
            a = a*a % mod;
            b >>= 1;
        }
        return res;
    }

    ll nCr(ll n, ll r){
        if(r > n) return 0;

        vector<ll> fact(n+1);
        fact[0] = 1;

        for(int i=1;i<=n;i++)
            fact[i] = fact[i-1]*i % mod;

        ll num = fact[n];
        ll den = fact[r]*fact[n-r] % mod;

        return num * modpow(den, mod-2) % mod;
    }

    int numberOfSets(int n, int k) {
        return nCr(n + k - 1, 2*k);
    }
};
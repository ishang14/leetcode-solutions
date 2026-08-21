#define ll long long

class Solution {
public:
    vector<ll> v;
    ll convert = 1;

    ll lcm(ll a, ll b)
    {
        return (a*b)/(gcd(a,b));
    }

    ll getCount(ll x)
    {
        ll ans = 0;
        for(int i=0;i<v.size();i++)
        {
            ans = ans + (x/v[i]);
        }
        return ans;
    }

    bool check(ll mid, vector<int> &v)
    {
        bool ans = false;
        for(int i=0;i<v.size();i++)
        {
            if(mid%(ll)v[i]==0)
            {
                ans = true;
                break;
            }
        }

        return ans;
    }

    void solve(vector<int> &coins, int index, int noe, ll lcmm)
    {
        //base case
        if(index==coins.size())
        {
            if(noe==0)
            {
                return;
            }

            if(noe%2==1)
            {
                v.push_back(lcmm);
            }
            else
            {
                v.push_back(-1*lcmm);
            }

            return;
        }

        //include
        ll newLcmm = lcm(coins[index], lcmm);
        solve(coins, index+1, noe+1, newLcmm);

        //exclude
        solve(coins, index+1, noe, lcmm);

        return;

    }
    
    long long findKthSmallest(vector<int>& coins, int k) {


        solve(coins, 0, 0, 1);

        ll low = 1;
        ll high = 1e12;

        ll K = k;

        ll ans;

        while(low<=high)
        {
            ll mid = (high-low)/2 + low;
            ll cnt = getCount(mid);

            if(cnt>K)
            {
                high = mid-1;
            }
            else if(cnt<K)
            {
                low = mid+1;
            }
            else
            {
                ans = mid;
                high = mid-1;
            }
        }

        return ans;
    }
};
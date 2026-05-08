class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();

        int mx = *max_element(nums.begin(), nums.end());

        vector<bool> isPrime(mx + 1, true);

        if (mx >= 0) isPrime[0] = false;
        if (mx >= 1) isPrime[1] = false;

        // Sieve of Eratosthenes
        for (int i = 2; i * i <= mx; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= mx; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        unordered_map<int, vector<int>> mp;

        // Store indices for each prime factor
        for (int i = 0; i < n; i++) {
            int x = nums[i];

            for (int p = 2; p * p <= x; p++) {
                if (x % p == 0) {

                    if (isPrime[p]) {
                        mp[p].push_back(i);
                    }

                    while (x % p == 0) {
                        x /= p;
                    }
                }
            }

            if (x > 1) {
                mp[x].push_back(i);
            }
        }

        queue<int> q;
        vector<bool> vis(n, false);

        q.push(0);
        vis[0] = true;

        int steps = 0;

        while (!q.empty()) {

            int s = q.size();

            while (s--) {

                int i = q.front();
                q.pop();

                if (i == n - 1) {
                    return steps;
                }

                // Move left
                if (i - 1 >= 0 && !vis[i - 1]) {
                    vis[i - 1] = true;
                    q.push(i - 1);
                }

                // Move right
                if (i + 1 < n && !vis[i + 1]) {
                    vis[i + 1] = true;
                    q.push(i + 1);
                }

                int val = nums[i];

                // Prime jump
                if (val <= mx && isPrime[val]) {

                    for (int nxt : mp[val]) {

                        if (!vis[nxt]) {
                            vis[nxt] = true;
                            q.push(nxt);
                        }
                    }

                    // Avoid repeated processing
                    mp[val].clear();
                }
            }

            steps++;
        }

        return -1;
    }
};
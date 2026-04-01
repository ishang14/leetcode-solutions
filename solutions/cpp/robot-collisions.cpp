class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indices(n);
        
        // initialize indices with 0 1 ... n-1
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }

        // sort indices based on the robot positions
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        vector<int> st; // stack to store indices of rightmoving robots
        for (int i : indices) {
            if (directions[i] == 'R') {
                // rightmoving robots are potential targets for left moving ones
                st.push_back(i);
            } else {
                // current robot is moving left (L)
                // collide with all possible right moving robots in the stack
                while (!st.empty() && healths[i] > 0) {
                    int top = st.back();
                    
                    if (healths[i] > healths[top]) {
                        // L robot wins , so R destroyed, L loses 1 health
                        healths[top] = 0;
                        healths[i] -= 1;
                        st.pop_back();
                    } else if (healths[i] < healths[top]) {
                        // R robot wins: L destroyed, R loses 1 health
                        healths[i] = 0;
                        healths[top] -= 1;
                    } else {
                        // tie: both destroyed
                        healths[i] = 0;
                        healths[top] = 0;
                        st.pop_back();
                    }
                }
            }
        }

        // collect healths of survivors in their original input order
        vector<int> result;
        for (int h : healths) {
            if (h > 0) {
                result.push_back(h);
            }
        }
        return result;
    }
};
class Solution {
public:
    vector<int> generateRow(int n) {
        vector<int> list;
        int res = 1;
        list.push_back(res);

        for (int i = 1; i <= n - 1; i++) {
            res = res * (n - 1 - i + 1);
            res = res / i;

            list.push_back(res);
        }

        return list;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        int n = numRows;

        for (int i = 1; i <= n; i++) {
            vector<int> ithRow = generateRow(i);
            ans.push_back(ithRow);
        }

        return ans;
    }
};
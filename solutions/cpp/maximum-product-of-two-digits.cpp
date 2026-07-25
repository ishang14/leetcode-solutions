class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);    // Convert n to string to access digits
        sort(s.begin(), s.end());   // Sort digits in ascending order
        int sz = s.size();
        return (s[sz - 1] - '0') * (s[sz - 2] - '0');  // Product of two largest digits
    }
};
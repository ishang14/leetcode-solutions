class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        return same(s1[0], s1[2], s2[0], s2[2]) &&
               same(s1[1], s1[3], s2[1], s2[3]);
    }

    bool same(char a, char b, char c, char d) {
        return (a == c && b == d) || (a == d && b == c);
    }
};
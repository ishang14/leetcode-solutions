class Solution {
public:
    bool isValid(string s) {

        unordered_map<char, char> braceMap;
        braceMap['('] = ')';
        braceMap['{'] = '}';
        braceMap['['] = ']';

        stack<char> st;

        for (char brace : s) {

            if (braceMap.count(brace)) {
                st.push(brace);
            } else {

                if (st.empty() || brace != braceMap[st.top()]) {
                    return false;
                }

                st.pop();
            }
        }

        return st.empty();
    }
};
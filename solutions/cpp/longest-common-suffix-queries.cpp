class Solution {
public:

    struct TrieNode {

        int child[26];
        int idx;

        TrieNode() {

            memset(child, -1, sizeof(child));
            idx = -1;
        }
    };

    vector<TrieNode> trie;

    Solution() {
        trie.push_back(TrieNode());
    }

    void updateNode(int node, vector<string>& wc, int i) {

        if (trie[node].idx == -1) {
            trie[node].idx = i;
            return;
        }

        int oldLen = wc[trie[node].idx].size();
        int newLen = wc[i].size();

        if (newLen < oldLen) {
            trie[node].idx = i;
        }
        else if (newLen == oldLen && i < trie[node].idx) {
            trie[node].idx = i;
        }
    }

    void insert(string &word, int i, vector<string>& wc) {

        int node = 0;

        updateNode(node, wc, i);

        for (char ch : word) {

            int c = ch - 'a';

            if (trie[node].child[c] == -1) {

                trie[node].child[c] = trie.size();

                trie.push_back(TrieNode());
            }

            node = trie[node].child[c];

            updateNode(node, wc, i);
        }
    }

    int match(string &word) {

        int node = 0;

        for (char ch : word) {

            int c = ch - 'a';

            if (trie[node].child[c] == -1) {
                break;
            }

            node = trie[node].child[c];
        }

        return trie[node].idx;
    }

    vector<int> stringIndices(vector<string>& wc, vector<string>& wq) {

        for (int i = 0; i < wc.size(); i++) {

            reverse(wc[i].begin(), wc[i].end());

            insert(wc[i], i, wc);
        }

        vector<int> ans;

        for (auto &q : wq) {

            reverse(q.begin(), q.end());

            ans.push_back(match(q));
        }

        return ans;
    }
};
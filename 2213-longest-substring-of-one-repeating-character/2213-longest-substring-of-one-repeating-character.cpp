class Solution {
    struct Node {
        int len, pre, suf, best;
        char l, r;
    };

    vector<Node> t;

    Node merge(Node a, Node b) {
        Node c{a.len + b.len, a.pre, b.suf, max(a.best, b.best), a.l, b.r};

        if (a.r == b.l) {
            c.best = max(c.best, a.suf + b.pre);

            if (a.pre == a.len)
                c.pre += b.pre;

            if (b.suf == b.len)
                c.suf += a.suf;
        }

        return c;
    }

    void build(int p, int l, int r, string& s) {
        if (l == r) {
            t[p] = {1, 1, 1, 1, s[l], s[l]};
            return;
        }

        int m = (l + r) / 2;
        build(p * 2, l, m, s);
        build(p * 2 + 1, m + 1, r, s);
        t[p] = merge(t[p * 2], t[p * 2 + 1]);
    }

    void update(int p, int l, int r, int i, char c) {
        if (l == r) {
            t[p] = {1, 1, 1, 1, c, c};
            return;
        }

        int m = (l + r) / 2;

        if (i <= m)
            update(p * 2, l, m, i, c);
        else
            update(p * 2 + 1, m + 1, r, i, c);

        t[p] = merge(t[p * 2], t[p * 2 + 1]);
    }

public:
    vector<int> longestRepeating(string s, string qc, vector<int>& qi) {
        int n = s.size();
        t.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans;
        for (int i = 0; i < qi.size(); i++) {
            update(1, 0, n - 1, qi[i], qc[i]);
            ans.push_back(t[1].best);
        }

        return ans;
    }
};
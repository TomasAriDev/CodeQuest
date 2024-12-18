#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class SegmentTree {
private:
    vector<int> tree;
    int n;

    void build(const string &s, int node, int start, int end) {
        if (start == end) {
            tree[node] = 1 << (s[start] - 'a');
        } else {
            int mid = (start + end) / 2;
            build(s, 2 * node + 1, start, mid);
            build(s, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] | tree[2 * node + 2];
        }
    }

    void update(int idx, char c, int node, int start, int end) {
        if (start == end) {
            tree[node] = 1 << (c - 'a');
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(idx, c, 2 * node + 1, start, mid);
            } else {
                update(idx, c, 2 * node + 2, mid + 1, end);
            }
            tree[node] = tree[2 * node + 1] | tree[2 * node + 2];
        }
    }

    int query(int L, int R, int node, int start, int end) {
        if (R < start || end < L) {
            return 0;
        }
        if (L <= start && end <= R) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int left_query = query(L, R, 2 * node + 1, start, mid);
        int right_query = query(L, R, 2 * node + 2, mid + 1, end);
        return left_query | right_query;
    }

public:
    SegmentTree(const string &s) {
        n = s.size();
        tree.resize(4 * n);
        build(s, 0, 0, n - 1);
    }

    void update(int idx, char c) {
        update(idx, c, 0, 0, n - 1);
    }

    int query(int L, int R) {
        return query(L, R, 0, 0, n - 1);
    }

    int count_unique_characters(int bitmask) {
        return __builtin_popcount(bitmask);
    }
};

int main() {
    string s;
    int q;
    cin >> s >> q;
    SegmentTree segTree(s);
    vector<int> results;

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos;
            char c;
            cin >> pos >> c;
            segTree.update(pos - 1, c);
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            int unique_chars = segTree.query(l - 1, r - 1);
            results.push_back(segTree.count_unique_characters(unique_chars));
        }
    }

    for (int res : results) {
        cout << res << "\n";
    }

    return 0;
}

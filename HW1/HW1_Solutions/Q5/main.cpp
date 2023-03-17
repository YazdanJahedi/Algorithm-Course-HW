#include "bits/stdc++.h"

using namespace std;

long long root;
map<long long, vector<long long>> tree;
long long max_dpt = 0;

vector<long long> BST_depth(long long c_root, long long par) {
    bool l_is_seen = false;
    long long max_r = -1, max_l = -1;

    vector<long long> ans(3, 0);     // depth  min  max
    ans[1] = INT32_MAX;    // min
    ans[2] = INT32_MIN;    // max

    for (long long i: tree[c_root]) {
        if (i == par) continue;

        vector<long long> dep = BST_depth(i, c_root);
        ans[1] = min(ans[1], dep[1]);
        ans[2] = max(ans[2], dep[2]);

        max_dpt = max(max_dpt, dep[0]);
        if (c_root > i && dep[2] < c_root) {
            l_is_seen = true;
            if (dep[0] > max_l) max_l = dep[0];
        } else if (c_root < i && l_is_seen && c_root < dep[1]) {
            if (dep[0] > max_r) max_r = dep[0];
        }
    }

    long long new_dpt = min(max_l, max_r) + 1;
    max_dpt = max(max_dpt, new_dpt);
    ans[0] = new_dpt; // val

    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n;
    cin >> n >> root;
    for (long long i = 0; i < n - 1; ++i) {
        long long n1, n2;
        cin >> n1 >> n2;
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }

    BST_depth(root, root);
    long long ans = (1 << (max_dpt + 1)) - 1;
    cout << ans << '\n';

    return 0;
}
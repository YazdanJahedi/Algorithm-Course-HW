#include "bits/stdc++.h"

using namespace std;

map<long long, vector<long long>> tree;
long long nodes, starting_node = 1;
double ans = 0;

void cal_ways(long long curr_node, long long parent, long long h, long long prob) {
    if (tree[curr_node].size() == 1 && curr_node != parent) {
//        cout << "node:  " << curr_node << "  h: " << h  << "  prob: " << prob << endl;
        ans += (h * 1.0 / prob);
        return;
    }

    for (long long i: tree[curr_node]) {
        if (i == parent) continue;
        if (curr_node == parent)
            cal_ways(i, curr_node, h + 1, (long long)(prob * (tree[curr_node].size())));
        else
            cal_ways(i, curr_node, h + 1, (long long)(prob * (tree[curr_node].size()-1)));

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> nodes;
    for (long long i = 0; i < nodes - 1; ++i) {
        long long e1, e2;
        cin >> e1 >> e2;
        tree[e1].push_back(e2);
        tree[e2].push_back(e1);
    }

    cal_ways(starting_node, starting_node, 0, 1);

    cout << fixed << setprecision(7) << ans << '\n';
    return 0;
}
/*
10
1 2
2 3
2 4
2 5
3 6
3 7
6 8
6 9
6 10





15
1 2
1 3
1 4
2 5
2 6
6 7
6 8
4 9
4 10
4 11
9 12
10 13
13 14
13 15


 */
#include "bits/stdc++.h"

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> loop;
bool found = true;

void cal_negative_loop() {
    vector<int> par(n + 1, -1);
    vector<int> d(n + 1, INT16_MAX);

    int z;
    for (int i = 0; i < n; i++) {
        z = -1;
        for (auto &edge: graph) {
            if (d[edge[0]] + edge[2] < d[edge[1]]) {
                d[edge[1]] = d[edge[0]] + edge[2];
                par[edge[1]] = edge[0];
                z = edge[1];
            }
        }
    }

    if (z == -1) {
        cout << "-1\n";
        found = false;
    } else {
        for (int i = 0; i < n; i++) z = par[z];

        for (int v = z;; v = par[v]) {
            loop.push_back(v);
            if (v == z && loop.size() > 1) return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        graph.push_back({u, v, cost});
    }

    cal_negative_loop();

    if (found) {
        cout << loop.size() - 1 << '\n';
        for (int i = loop.size() - 1; i >= 0; i--)
            cout << loop[i] << " ";
    }

    return 0;
}

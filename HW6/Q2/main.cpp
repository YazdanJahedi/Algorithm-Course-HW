#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    for (int x = 0; x < t; ++x) {
        int n, m, p, s, g, h;
        cin >> n >> m >> p >> s >> g >> h;
        int w_g_h;
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            if ((u == h && v == g) || (u == g && v == h))
                w_g_h = w;
            adj[u - 1].push_back({v - 1, w});
            adj[v - 1].push_back({u - 1, w});
        }
        vector<int> ps;
        for (int i = 0; i < p; ++i) {
            int in;
            cin >> in;
            ps.push_back(in);
        }
        std::sort(ps.begin(), ps.end());

        vector<int> destination_s(n, INT32_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        destination_s[s - 1] = 0;
        pq.push({0, s - 1});

        while (!pq.empty()) {
            int d = pq.top().first, u = pq.top().second;
            pq.pop();
            if (d > destination_s[u]) continue;
            for (auto&[v, w]: adj[u]) {
                if (destination_s[u] + w < destination_s[v]) {
                    destination_s[v] = destination_s[u] + w;
                    pq.push({destination_s[v], v});
                }
            }
        }

        vector<int> destination_h(n, INT32_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_h;
        destination_h[h - 1] = 0;
        pq_h.push({0, h - 1});

        while (!pq_h.empty()) {
            int d = pq_h.top().first, u = pq_h.top().second;
            pq_h.pop();
            if (d > destination_h[u]) continue;
            for (auto&[v, w]: adj[u]) {
                if (destination_h[u] + w < destination_h[v]) {
                    destination_h[v] = destination_h[u] + w;
                    pq_h.push({destination_h[v], v});
                }
            }
        }

        vector<int> destination_g(n, INT32_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_g;
        destination_g[g - 1] = 0;
        pq_g.push({0, g - 1});

        while (!pq_g.empty()) {
            int d = pq_g.top().first, u = pq_g.top().second;
            pq_g.pop();
            if (d > destination_g[u]) continue;
            for (auto&[v, w]: adj[u]) {
                if (destination_g[u] + w < destination_g[v]) {
                    destination_g[v] = destination_g[u] + w;
                    pq_g.push({destination_g[v], v});
                }
            }
        }

        for (int ppp: ps) {
            int u = ppp - 1;
//            cout << "here:  " << ppp << endl;

            if (destination_s[u] != INT32_MAX) {
//                cout << "dest_s[ppp]  " << destination_s[u] << endl;
//                cout << "dest_s[g]  " << destination_s[g - 1] << endl;
//                cout << "dest_s[h]  " << destination_s[h - 1] << endl;
//                cout << "dest_g[ppp]  " << destination_g[u] << endl;
//                cout << "dest_h[ppp]  " << destination_h[u] << endl;
//                cout << "wgh  " << w_g_h << endl;

                if (destination_s[g - 1] + w_g_h + destination_h[u] == destination_s[u] ||
                    destination_s[h - 1] + w_g_h + destination_g[u] == destination_s[u])
                    cout << ppp << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}

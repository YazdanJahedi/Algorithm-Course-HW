#include "bits/stdc++.h"

using namespace std;

int n, m, start;
vector<int> dist(10010 + 1, INT32_MAX);

void dijkstra(vector<vector<pair<int, int>>> &graph) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto v: graph[u]) {
            if (dist[v.first] > dist[u] + v.second) {
                dist[v.first] = dist[u] + v.second;
                pq.push(make_pair(dist[v.first], v.first));
            }
        }
    }
}

void print_ans() {
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        if (i != start) {
            if (dist[i] == INT32_MAX) {
                cout << "-1";
                return;
            }
            ans = max(ans, dist[i]);
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    cin >> n >> m >> start;
    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        graph[u].push_back(make_pair(v, cost));
    }
    dijkstra(graph);
    print_ans();
    return 0;
}
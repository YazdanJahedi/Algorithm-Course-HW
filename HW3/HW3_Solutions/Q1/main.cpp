#include "bits/stdc++.h"

using namespace std;

long n, m, final_node, starting_node = 0, h = 0, temp_num = 1;
map<long, vector<long>> graph;
queue<long> q;
char vis[200000] = {};
long parent[200000] = {};
string path = "";

void find_shortest_way(long start) {
    vis[start] = 1;
    q.push(start);
    parent[start] = -1;

    while (!q.empty()) {
        long curr = q.front();
        q.pop();
        if (curr == final_node) return;
        for (long i: graph[curr]) {
            if (!vis[i]) {
                q.push(i);
                vis[i] = 1;
                parent[i] = curr;
            }
        }
    }
}

void print_path(long final) {
    if (parent[final] == -1) {
        path += to_string(starting_node) + " ";
        return;
    }
    print_path(parent[final]);
    h++;
    if(final < 100000) {
        path += to_string(final) + " ";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> final_node;

    for (int i = 0; i < m; ++i) {
        long e1, e2, cost;
        cin >> e1 >> e2 >> cost;
        if (cost == 1) {
            graph[e1].push_back(e2);
            graph[e2].push_back(e1);
        } else {
            long temp = 100000 + temp_num++;
            graph[e1].push_back(temp);
            graph[temp].push_back(e2);
            graph[e2].push_back(temp);
            graph[temp].push_back(e1);
        }
    }

    find_shortest_way(starting_node);
    print_path(final_node);
    cout << h << '\n' << path << '\n';
    return 0;
}

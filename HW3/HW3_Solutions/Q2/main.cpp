#include "bits/stdc++.h"

#define MAX_NODE 200
using namespace std;

map<int, vector<int>> graph;
int parent[MAX_NODE][MAX_NODE] = {};

vector<int> cal_cycle_from_node(int starting) {
    // pair < node, parent >
    queue<pair<int, int>> q;
    int height[MAX_NODE] = {};
    char visited[MAX_NODE] = {};

    q.push(make_pair(starting, starting));
    // visited[starting] = 1;
    parent[starting][starting] = -1;

    while (!q.empty()) {
        int curr = q.front().first;
        int par = q.front().second;
        q.pop();

        for (int i: graph[curr]) {
            if (i == starting || i == par) continue;
            else if (visited[i]) {
                return {starting, curr, i, height[curr] + height[i] + 1};
            } else {
                height[i] = height[curr] + 1;
                q.push(make_pair(i, curr));
                parent[starting][i] = curr;
                visited[i] = 1;
            }
        }
    }

    return {starting, -1, -1, INT32_MAX};
}


int best_len = INT32_MAX;
int best_starting = -1, best_f1 = -1, best_f2 = -1;

void find_best_way(int n) {
    for (int i = 0; i < n; ++i) {
        vector<int> v = cal_cycle_from_node(i);
        int starting = v[0], f1 = v[1], f2 = v[2], len = v[3];

        if (len < best_len) {
            best_starting = starting;
            best_f1 = f1;
            best_f2 = f2;
            best_len = len;
        }

    }
}

void printF2(int curr){
    if(parent[best_starting][curr] == -1){
        cout << curr << ' ';
        return;
    }

    printF2(parent[best_starting][curr]);
    cout << curr << ' ';
}

void printF1(int curr){
    if(parent[best_starting][curr] == -1){
        cout << curr << ' ';
        return;
    }

    cout << curr << ' ';
    printF1(parent[best_starting][curr]);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int e1, e2;
        cin >> e1 >> e2;
        graph[e1].push_back(e2);
        graph[e2].push_back(e1);
    }

    find_best_way(n);
//    cout << "start: " << best_starting << "  f1: " << best_f1 << "  f2: " << best_f2 << "  h: " << best_len << endl;
    cout << best_len << '\n';
    printF2(best_f2);
    printF1(best_f1);


    return 0;
}
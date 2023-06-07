#include "bits/stdc++.h"

using namespace std;

long long n;
priority_queue<vector<long long>, vector<vector<long long>>, greater<>> q; // tournaments
long long total_best = 0;
long long val[100010] = {};

void cal() {
    for (long long i = 0; i < n; ++i) {
        vector<long long> v = q.top();
        q.pop();
        long long s = v[1], t = v[0], p = v[2];

        long long base_val = 0;
        for (long long j = s; j > 0; --j) {
            if(val[j] != 0) {
                base_val = val[j];
                break;
            }
        }

        long long val2 = 0;
        for (long long j = t; j > s; --j) {
            if(val[j] != 0) {
                val2 = val[j];
                break;
            }
        }
        val[s] = base_val;
        val[t] = max(val2, val[s] + p);
        total_best = max(total_best, val[t]);

    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    cin >> n >> n; // first n is temp
    for (long long i = 0; i < n; ++i) {
        long long s, t, p;
        cin >> s >> t >> p;
        q.push({t, s, p});
    }
    cal();

    cout << total_best << '\n';

    return 0;
}

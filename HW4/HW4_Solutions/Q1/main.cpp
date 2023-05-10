#include "bits/stdc++.h"

using namespace std;

#define MAX 2010

long long n, m;
long long ground[MAX][MAX] = {};
long long best[MAX + 1][MAX + 1] = {};

void cal_best() {
    for (long long i = 1; i <= m; ++i)
        for (long long j = 1; j <= n; ++j)
            best[i][j] = max(best[i-1][j], best[i][j-1]) + ground[i-1][j-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> m >> n;
    for (long long i = 0; i < m; ++i) {
        for (long long j = 0; j < n; ++j) {
            long long in;
            cin >> in;
            ground[i][j] = in;
            if (i == 0 && j >= 1) best[i][j + 1] = -INT32_MAX;
            if (j == 0 && i >= 1) best[i + 1][j] = -INT32_MAX;
        }
    }

    cal_best();

//    for (int i = 0; i < m+1; ++i) {
//        for (int j = 0; j < n+1; ++j) {
//            cout << best[i][j] << ' ';
//        }
//        cout << endl;
//    }
//    cout << "----------" << endl;

    cout << best[m][n] << '\n';

    return 0;
}

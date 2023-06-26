#include "bits/stdc++.h"

using namespace std;

int n;
int xs[2010];
int ys[2010];

long long distance(int x1, int y1, int x2, int y2) {
    return pow(x1 - x2, 2) + pow(y1 - y2, 2);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> xs[i] >> ys[i];


    int best_x1, best_x2, best_y1, best_y2;
    long long min_dist = INT32_MAX;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            long long dist = distance(xs[i], ys[i], xs[j], ys[j]);
            if (dist < min_dist) {
                min_dist = dist;
                best_x1 = xs[i];
                best_x2 = xs[j];
                best_y1 = ys[i];
                best_y2 = ys[j];
            }
        }
    }

    cout << best_x1 << " " << best_y1 << '\n'
         << best_x2 << " " << best_y2 << '\n';

    return 0;
}

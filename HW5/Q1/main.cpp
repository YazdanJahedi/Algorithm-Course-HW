#include "bits/stdc++.h"

using namespace std;

void cal_path(const string& path) {
    int x = 0, y = 0;
    for (char i: path) {
        if (i == 'A') {
            x += 2;
        } else if (i == 'B') {
            x++;
            y++;
        } else if (i == 'C') {
            x--;
            y++;
        } else if (i == 'D') {
            x -= 2;
        } else if (i == 'E') {
            x--;
            y--;
        } else if (i == 'F') {
            x++;
            y--;
        }
    }

    x = abs(x); y = abs(y);
    int ans = y;
    if(y <= x)
        ans += abs(x-y)/2;

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        string path;
        cin >> path;
        cal_path(path);
    }

    return 0;
}

#include "bits/stdc++.h"

using namespace std;

int n;
string a, b;


int cal_cost() {
    int ans = 0;

    for (int i = 0; i < n-1; ++i) {
        if (a[i] == b[i]) continue;

        ans++;
        if(a[i+1] != b[i+1] && a[i] != a[i+1]) {
            char temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
        } else {
            if(a[i] == '1')
                a[i] = '0';
            else a[i] = '1';
        }
    }

    if(a[n-1] != b[n-1])
        ans++;

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    cin >> a >> b;

    cout << cal_cost() << '\n';
    return 0;
}

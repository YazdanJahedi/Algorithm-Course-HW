#include<bits/stdc++.h>

using namespace std;

int n;
int ans;
int arr[17] = {};

bool is_there(int num, int end) {
    for (int i = 1; i < end; ++i)
        if (arr[i] == num)
            return true;
    return false;
}

void cal(int h) {
    if (h > n+1) return;
    if (n + 1 == h ){
        ans++;
//        for (int i = 1; i <= n; ++i) {
//            cout << arr[i] << " ";
//        }
//        cout << endl;
    }


    for (int i = 1; i <= n; ++i) {
        if (!is_there(i, h) && (i % h == 0 || h % i == 0)) {
            arr[h] = i;
            cal(h + 1);
        }
    }
}

int main() {
    cin >> n;
    cal(1);
    cout << ans;
    return 0;
}

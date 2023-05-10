#include "bits/stdc++.h"

using namespace std;
#define MAX 100010

int line[MAX] = {};
int n, lis_max = 0;

int inc_line[MAX] = {};
int f[MAX] = {};

int dec_line[MAX] = {};
int b[MAX] = {};

int cnt[MAX] = {};
int ans[MAX] = {};

void print(int arr[MAX]) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int bin_search_1(int l, int r, int key) {
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (inc_line[m] >= key)
            r = m;
        else
            l = m;
    }

    return r;
}

void cal_f() {
    inc_line[0] = line[0];
    f[0] = 0;
    int last = 0;
    for (int i = 1; i < n; ++i) {
        if (line[i] < inc_line[0]) {
            inc_line[0] = line[i];
            f[i] = 0;
        } else if (line[i] > inc_line[last]) {
            inc_line[++last] = line[i];
            f[i] = last;
            lis_max = last;
        } else {
            int ind = bin_search_1(-1, last, line[i]);
            inc_line[ind] = line[i];
            f[i] = ind;
        }
    }
}

int bin_search_2(int l, int r, int key) {
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (dec_line[m] <= key)
            r = m;
        else
            l = m;
    }

    return r;
}

void cal_b() {
    dec_line[0] = line[n - 1];
    b[n - 1] = 0;
    if (b[n - 1] + f[n - 1] < lis_max) {
        ans[n - 1] = 1;
    } else {
        cnt[f[n - 1]]++;
    }

    int last = 0;
    for (int i = n - 2; i >= 0; --i) {
        if (line[i] > dec_line[0]) {
            dec_line[0] = line[i];
            b[i] = 0;
        } else if (line[i] < dec_line[last]) {
            dec_line[++last] = line[i];
            b[i] = last;
        } else {
            int ind = bin_search_2(-1, last, line[i]);
            dec_line[ind] = line[i];
            b[i] = ind;
        }

        if (b[i] + f[i] < lis_max) {
            ans[i] = 1;
        } else {
            cnt[f[i]]++;
        }
    }
}

void print_ans() {
    for (int i = 0; i < n; ++i) {
        if (ans[i] == 1) {
            cout << 1;
        } else {
            if(cnt[f[i]] == 1) cout << 3;
            else cout << 2;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);


    cin >> n;
    for (int i = 0; i < n; ++i) {
        int d;
        cin >> d;
        line[i] = d;
    }

    cal_f();
    cal_b();
    print_ans();
    return 0;
}

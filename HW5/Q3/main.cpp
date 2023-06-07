#include "bits/stdc++.h"

using namespace std;
int n, base;
long long sum_of_all = 0;
int fariborz;
int numbers[1010];
bool t[1010][100010] = {};
char c[1010][100010] = {};
int fx = 0;

void print_index(int i, int j) {
    if (i <= 0 || j <= 0) return;
    if (c[i][j] != 'o') print_index(i - 1, j);
    else {
        print_index(i - 1, j - numbers[i - 1]);
        cout << i << " ";
    }
}

int cal_minimum_sum_greater_than_base() {
    for (int i = 0; i < sum_of_all + 1; ++i)
        t[0][i] = false;
    for (int i = 0; i < n + 1; ++i)
        t[i][0] = true;


    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < sum_of_all + 1; j++) {
            if (numbers[i - 1] <= j) {
                t[i][j] = t[i - 1][j - numbers[i - 1]] || t[i - 1][j];
                if (t[i - 1][j - numbers[i - 1]])
                    c[i][j] = 'o';
            } else {
                t[i][j] = t[i - 1][j];
            }
        }

    for (int j = base; j <= sum_of_all; j++) {
        if (!t[n][j]) continue;
        return j;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> base;
    n--;
    base++;
    cin >> fariborz;
    base -= fariborz;
    n =  min(n, 134);

    for (int i = 0; i <n; ++i) {
        int num;
        cin >> num;
        numbers[i] = num;
        sum_of_all += num;
    }

    fx = cal_minimum_sum_greater_than_base();

    cout << 0 << " ";
    print_index(n, fx);
    cout << endl;

    return 0;
}

/*
5 30
10 7 12 3 21
 -> 0 4

15 960
2 261 148 260 445 595 558 127 142 268 490 874 137 168 805
 -> 0 3 6 8
 */
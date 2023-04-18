#include "bits/stdc++.h"

using namespace std;

char ground[200][200] = {};
vector<pair<int, int>> not_decided;
int n, m;

bool can_be_1(int i, int j) {
    return ground[i - 1][j] == 1 || ground[i + 1][j] == 1 || ground[i][j - 1] == 1 || ground[i][j + 1] == 1;
}

bool can_be_0(int i, int j) {
    return ground[i - 1][j] == 0 && ground[i + 1][j] == 0 && ground[i][j - 1] == 0 && ground[i][j + 1] == 0;
}

void printGround() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << (int) ground[i][j];
        }
        cout << '\n';
    }
}

void cal_for_others() {
    while (!not_decided.empty()) {
        bool in_loop = true;
        for (int i = 0; i < not_decided.size(); ++i) {
            int ii = not_decided[i].first;
            int jj = not_decided[i].second;
            if (can_be_1(ii, jj)) {
                in_loop = false;
                not_decided.erase(not_decided.begin() + i);
                ground[ii][jj] = 1;
            } else if (can_be_0(ii, jj)) {
                in_loop = false;
                not_decided.erase(not_decided.begin() + i);
                ground[ii][jj] = 0;
            }
        }
        if (in_loop) {
            for (auto &i: not_decided) {
                int ii = i.first;
                int jj = i.second;
                ground[ii][jj] = 0;
            }
            return;
        }

    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            if (((i == 0 || i == n - 1) || (j == 0 || j == m - 1)) && c == 'W')
                ground[i][j] = 1;
            else {
                char temp = c - 'R';
                if (temp == 5)
                    not_decided.emplace_back(i, j);
                ground[i][j] = temp;
            }
            // R : 0
            // W : 5
        }
    }


    cal_for_others();
    printGround();

    return 0;
}

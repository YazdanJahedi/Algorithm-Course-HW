#include "bits/stdc++.h"

using namespace std;
#define MAX_LEN 110

string first, second, forbidden;
int first_len, second_len;
int l[MAX_LEN][MAX_LEN] = {};
char t[MAX_LEN][MAX_LEN] = {};

void print_l() {
    for (int i = 0; i <= second_len; ++i) {
        for (int j = 0; j <= first_len; ++j)
            cout << l[i][j] << " ";
        cout << endl;
    }
}

void print_t() {
    for (int i = 0; i <= second_len; ++i) {
        for (int j = 0; j <= first_len; ++j) {
            if (t[i][j] < 10)
                cout << (int) t[i][j] << " ";
            else
                cout << t[i][j] << " ";
        }
        cout << endl;
    }
}

bool contains(const string &str, const string &subString) {
    return str.find(subString) != string::npos;
}

void create_l_t() {
    for (int i = 1; i <= second_len; ++i) {
        for (int j = 1; j <= first_len; ++j) {
            if (second[i - 1] == first[j - 1]) {
                l[i][j] = 1 + l[i - 1][j - 1];
                t[i][j] = 'o';
            } else {

//                l[i][j] = max(l[i - 1][j], l[i][j - 1]);

                if (l[i - 1][j] > l[i][j - 1]) {
                    l[i][j] = l[i - 1][j];
                    t[i][j] = 'u';
                } else {
                    l[i][j] = l[i][j - 1];
                    t[i][j] = 'l';
                }
            }
        }
    }
}

string ans = "";

void find_ans() {
    int x = second_len, y = first_len;
    while (t[x][y]) {
        if (t[x][y] == 'o') {
            ans += first[y - 1];
            x--;
            y--;
        } else if (t[x][y] == 'l') {
            y--;
        } else {
            x--;
        }
    }
}

void clean_ans() {
    while(contains(ans, forbidden)){
        int ind = ans.find(forbidden);
        ans.erase(ans.begin() + ind);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> first >> second >> forbidden;
    first_len = (int) first.length();
    second_len = (int) second.length();

    create_l_t();
//    print_l();
//    cout << "`````````````````````````" << endl;
//    print_t();

    find_ans();
    ans = string(ans.rbegin(), ans.rend());
    clean_ans();

    if(!ans.empty())
        cout << ans << '\n';
    else
        cout << 0 << '\n';
    return 0;
}

/*

aggtab
gxtxayb
s


 */
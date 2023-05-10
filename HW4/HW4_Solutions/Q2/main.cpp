#include "bits/stdc++.h"

using namespace std;

map<int, int> base_line; // counts each digit in the base_line
map<int, int> second_line;
priority_queue<int> secondL_count;
priority_queue<int> firstL_count;
int ans = 0;

vector<int> temp;

void cal() {
    while(!firstL_count.empty()){
        int empty_group_space = firstL_count.top();
        firstL_count.pop();

        int s_size = (int) secondL_count.size();
        int len = min(s_size, empty_group_space);

        for (int i = 0; i < len; ++i) {
            int count = secondL_count.top();
            secondL_count.pop();
            count--;
            ans++;
            if(count != 0) {
                temp.push_back(count);
            }
        }

        for (int & i : temp) {
            secondL_count.push(i);
        }
        temp.clear();

    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, digit;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> digit;
        base_line[digit]++;
    }

    for (int i = 0; i < n; ++i) {
        cin >> digit;
        second_line[digit]++;
    }

    for (auto const &x: second_line)
        secondL_count.emplace(x.second); // count of digit
    for (auto const &x: base_line)
        firstL_count.emplace(x.second); // count of digit

    cal();
    cout << ans << '\n';
    return 0;
}


/*
10
1 2 2 4 4 3 1 1 4 1
2 2 4 1 1 3 1 2 1 1
-> 9


10
3 2 1 4 1 5 3 1 2 2
2 5 4 3 1 2 4 4 4 4
-> 10


 */
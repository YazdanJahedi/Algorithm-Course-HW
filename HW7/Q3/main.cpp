#include <bits/stdc++.h>

using namespace std;

long long n;
long long x[1000010];
long long t[1000010];
long long count = 0;

long long merge(long long int xt[], pair<long long, long long> p, long long int tt[]) {
    long long m = (p.first + p.second) / 2 + 1, merge_c = 0;
    for (int i = p.first; i <= (p.first + p.second) / 2; ++i) {
        bool flag = true;
        while (m <= p.second) {
            if (xt[i] <= 2 * xt[m])
                break;
            m++;
            flag = false;
        }

        if (!flag) {
            m--;
            merge_c += m - (p.first + p.second) / 2;
        }
    }

    m = (p.first + p.second) / 2 + 1;
    long long l2 = p.first, l1 = p.first;
    while (m <= p.second && l2 <= (p.first + p.second) / 2) {
        if (xt[l2] > xt[m])
            tt[l1++] = xt[m++];
        else
            tt[l1++] = xt[l2++];
    }

    while (l2 <= (p.first + p.second) / 2)
        tt[l1++] = xt[l2++];
    while (m <= p.second)
        tt[l1++] = xt[m++];
    for (int f = p.first; f <= p.second; f++)
        xt[f] = tt[f];

    return merge_c;
}

long long cal(long long int xt[], pair<long long, long long> p, long long int tt[]) {
    long long answer = 0;
    if (p.second < p.first) {
        answer += cal(xt, make_pair(p.first, (p.second + p.first) / 2 + 1), tt);
        answer += cal(xt, make_pair((p.second + p.first) / 2, p.second), tt);
        answer += merge(xt, make_pair(p.second, p.first), tt);
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (long long i = 0; i < n; ++i) cin >> x[i];

    long long ans = cal(x, make_pair(n - 1, 0), t);
    cout << ans;

    return 0;
}

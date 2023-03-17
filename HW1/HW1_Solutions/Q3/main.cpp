#include <iostream>

using namespace std;

int l[500000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, size;
    cin >> n;
    cin >> size;
    for (int i = 0; i < size; ++i) cin >> l[i];

    for (int t = 0; t < n; ++t) {
        int k;
        cin >> k;

        if (k <= 0) continue;

        for (int i = 0; i < size - (size % k); i += k) {
            int left = i;
            int right = i + k - 1;
            for (int j = 0; j < k/2; ++j)
                swap(l[left++], l[right--]);
        }
    }

    for (int i = 0; i < size; i++) cout << l[i];

    return 0;
}

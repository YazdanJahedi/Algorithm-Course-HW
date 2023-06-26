#include "bits/stdc++.h"

using namespace std;

int n;
int arr[20];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int subset1_sum = 0, subset2_sum = 0;
    for (int i = 0; i < n / 2; i++)
        subset1_sum += arr[i];
    for (int i = n / 2; i < n; i++)
        subset2_sum += arr[i];

    int diff = abs(subset1_sum - subset2_sum);
    int m_diff = diff;
    int ind = n / 2;
    while (ind < n) {
        subset1_sum += arr[ind];
        subset2_sum -= arr[ind];
        diff = abs(subset1_sum - subset2_sum);
        if (diff >= m_diff) break;
        else m_diff = diff;
        ind++;
    }

    for (int i = ind - n / 2; i < ind; i++) cout << arr[i] << " ";

    return 0;
}

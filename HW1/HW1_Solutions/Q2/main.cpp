#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // n: number of queues    q: lines   < 300 000
    int n, q;
    cin >> n;
    cin >> q;
    int *first_ptr = new int[n];
    int q_size = 0;
    int queue[300001]; // max valid size
    long long sums[300002] = {0};

    for (int i = 0; i < q; ++i) {
        int command;
        cin >> command;
        if (command == 1) {
            int val;
            cin >> val;
            queue[q_size] = val;
            if (q_size == 0)
                sums[q_size + 1] = val;
            else
                sums[q_size + 1] = sums[q_size] + val;

            q_size++;

        } else {
            // command ==2
            int q_num;
            int pop_num;
            cin >>  q_num;
            cin >> pop_num;

            int curr_first = first_ptr[q_num-1];

            long long sum = sums[curr_first + pop_num] - sums[curr_first];
            first_ptr[q_num-1] = curr_first + pop_num;
            cout << sum << '\n';
        }
    }

    return 0;
}

#include "iomanip"
#include "iostream"
#include "vector"
#include "queue"

using namespace std;

void insert(double median, int in, priority_queue<int> &max_h, priority_queue<int, vector<int>, greater<>> &min_h) {
    if (max_h.empty() || in < median)
        max_h.push(in);
    else
        min_h.push(in);
}

void balance(priority_queue<int> &max_h, priority_queue<int, vector<int>, greater<>> &min_h) {
    if (max_h.size() - min_h.size() == 2) {
        int t = max_h.top();
        min_h.push(t);
        max_h.pop();
    } else if (min_h.size() - max_h.size() == 2) {
        int t = min_h.top();
        max_h.push(t);
        min_h.pop();
    }
}

double
cal_median(int round, const priority_queue<int> &max_h, const priority_queue<int, vector<int>, greater<>> &min_h) {
    if (round % 2 == 0)
        return (max_h.top() + min_h.top()) / 2.0;
    else if (max_h.size() > min_h.size())
        return max_h.top();
    else
        return min_h.top();
}

int main() {
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<>> min_heap;
    double median = 0;
    int in = 0;
    int round = 0;

    while (true) {
        round++;
        cin >> in;
        if (in == -1)
            break;
        insert(median, in, max_heap, min_heap);
        balance(max_heap, min_heap);
        median = cal_median(round, max_heap, min_heap);
        printf("%.1f\n", median);
    }

    return 0;
}

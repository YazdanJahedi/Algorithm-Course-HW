#include "bits/stdc++.h"
using namespace std;

int n, k;
int works[100010] = {};
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> heap;


bool cal(){
    while(!heap.empty()){
        pair<int, int> p = heap.top();
        heap.pop();
        int deadline = p.first;
        int dur = p.second;

        int ind = deadline;
        bool ok = false;
        while(ind >= deadline - dur && ind > 0){
            if(works[ind] < k) {
                works[ind]++;
                ok = true;
                break;
            }
            ind--;
        }
        if(!ok) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int s, d;
        cin >> s >> d;
        heap.push(make_pair(d, d - s)); // deadline, days to do
    }

    cal()? cout << "YES": cout << "NO";

    return 0;
}

#include <iostream>
#include <queue>
#include <deque>
using namespace std;

typedef long long ll;

int rev(int dir) {
    if (dir == 0) return 1;
    else return 0;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, k, m;
    cin >> n >> k >> m;
    deque<int> d;
    for (int i=1; i<=n; i++) d.push_back(i);
    int cntR = 0, cntP = 0; // 각각 remove 개수와 체크한 사람 수를 count
    int dir = 0;            // 시계 방향 (0), 반시계 방향(1)
    while (!d.empty()) {
        int curr;
        if (dir == 0) {
            curr = d.front(); d.pop_front();
            cntP++;
            if (cntP == k) {
                cntP=0, cntR++;
                cout << curr << '\n';
            }
            else d.push_back(curr);
            if (cntR == m) cntR=0, dir=rev(dir);
        } else {
            curr = d.back(); d.pop_back();
            cntP++;
            if (cntP == k) {
                cntP=0, cntR++;
                cout << curr << '\n';
            }
            else d.push_front(curr);
            if (cntR == m) cntR=0, dir=rev(dir);
        }
    }
    return 0;
}
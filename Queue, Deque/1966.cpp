#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll t;
    cin >> t;
    int n, m, x;
    while (t--) {
        cin >> n >> m;
        queue<pair<int, int> > printer; // 문서 {index, 중요도}
        vector<int> v;      // 중요도 저장
        for (int i=0; i<n; i++) {
            cin >> x;
            printer.push(p(i, x));
            v.push_back(x);
        }
        sort(v.rbegin(), v.rend());
        ll cnt = 0;
        while (!printer.empty()) {
            pair<int, int> curr;
            curr = printer.front(); printer.pop();
            if (curr.second == v[cnt]) { // 가장 높은 중요도 -> print할 예정
                cnt++;
                if (curr.first == m) break;
            } else {
                printer.push(curr);
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
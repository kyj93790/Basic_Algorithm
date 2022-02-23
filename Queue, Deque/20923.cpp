#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
deque<ll> d, s, dg, sg;
ll n, m, x, y, a, b, c, t;

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> m;
    for (ll i=0; i<n; i++) {
        cin >> x >> y;
        d.push_back(x);
        s.push_back(y);
    }
    for (ll i=0; i<m; i++) {
        if (t == 0) {   // dodo turn
            dg.push_back(d.back()); d.pop_back();
            if (d.empty()) {
                cout << "su\n";
                return 0;
            }
            t = 1;
        } else { // suyeon turn
            sg.push_back(s.back()); s.pop_back();
            if (s.empty()) {
                cout << "do\n";
                return 0;
            }
            t = 0;
        }
        // 각 그라운드의 top 값 설정
        if (!dg.empty()) a = dg.back();
        else a = 0;
        if (!sg.empty()) b = sg.back();
        else b = 0;
        
        if (a == 5 || b == 5) { // dodo win
            while (!sg.empty()) {
                d.push_front(sg.front()); sg.pop_front();
            }
            while (!dg.empty()) {
                d.push_front(dg.front()); dg.pop_front();
            }
        } else if (a + b == 5) { // suyeon win
            while (!dg.empty()) {
                s.push_front(dg.front()); dg.pop_front();
            }
            while (!sg.empty()) {
                s.push_front(sg.front()); sg.pop_front();
            }
        }
    }
    if (d.size() > s.size()) cout << "do\n";
    else if (d.size() == s.size()) cout << "dosu\n";
    else cout << "su\n";
    return 0;
}
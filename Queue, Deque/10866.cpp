#include <iostream>
#include <queue>
#include <deque>
using namespace std;

typedef long long ll;

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    deque<int> d;
    ll n, x;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        if (!s.compare("push_front")) {
            cin >> x;
            d.push_front(x);
        } else if (!s.compare("push_back")) {
            cin >> x;
            d.push_back(x);
        } else if (!s.compare("pop_front")) {
            if (d.empty()) cout << -1 << '\n';
            else {
                cout << d.front() << '\n';
                d.pop_front();
            }
        } else if (!s.compare("pop_back")) {
            if (d.empty()) cout << -1 << '\n';
            else {
                cout << d.back() << '\n';
                d.pop_back();
            }
        } else if (!s.compare("size")) {
            cout << d.size() << '\n';
        } else if (!s.compare("empty")) {
            cout << d.empty() << '\n';
        } else if (!s.compare("front")) {
            if (d.empty()) cout << -1 << '\n';
            else cout << d.front() << '\n';
        } else if (!s.compare("back")) {
            if (d.empty()) cout << -1 << '\n';
            else cout << d.back() << '\n';
        }
    }
    return 0;
}
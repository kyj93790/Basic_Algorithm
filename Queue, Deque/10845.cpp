#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    queue<int> q;
    ll n, x;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        if (!s.compare("push")) {
            cin >> x;
            q.push(x);
        } else if (!s.compare("pop")) {
            if (q.empty()) cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        } else if (!s.compare("size")) {
            cout << q.size() << '\n';
        } else if (!s.compare("empty")) {
            cout << q.empty() << '\n';
        } else if (!s.compare("front")) {
            if (q.empty()) cout << -1 << '\n';
            else cout << q.front() << '\n';
        } else if (!s.compare("back")) {
            if (q.empty()) cout << -1 << '\n';
            else cout << q.back() << '\n';
        }
    }
    return 0;
}
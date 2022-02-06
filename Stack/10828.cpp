#include <iostream>
#include <stack>
#include <string>
using namespace std;

typedef long long ll;

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    stack<int> s;
    ll n;
    cin >> n;
    while (n--) {
        string cmd;
        ll x;
        cin >> cmd;
        if (!cmd.compare("push")) {
            cin >> x;
            s.push(x);
        } else if (!cmd.compare("pop")) {
            if (!s.empty()) {
                cout << s.top() << '\n';
                s.pop();
            }
            else cout << -1 << '\n';
        }
        else if (!cmd.compare("size")) cout << s.size() << '\n';
        else if (!cmd.compare("empty")) cout << s.empty() << '\n';
        else if (!cmd.compare("top")) {
            if (s.empty()) cout << -1 << '\n';
            else cout << s.top() << '\n';
        }
    }
    return 0;
}
#include <iostream>
#include <stack>
using namespace std;

typedef long long ll;
stack<ll> s;

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    string str;
    cin >> str;
    for (ll i=0; i<str.length(); i++) {
        if (str[i] == '(') {
            s.push(-1);
        } else { // ')'
            ll ans = 0;
            while (!s.empty() && s.top() > 0) {
                ans += s.top();
                s.pop();
            }
            if (s.empty() || s.top() != -1) { // 짝이 안맞음
                s.push(ans);
                s.push(-2);
            } else {
                s.pop();
                s.push(ans+2);
            }
        }
    }
    ll max = 0;
    ll temp = 0;
    while (!s.empty()) {
        if (s.top() > 0) temp += s.top();
        else {
            if (max < temp) max = temp;
            temp = 0;
        }
        s.pop();
    }
    if (max < temp) max = temp;
    cout << max << '\n';
    return 0;
}
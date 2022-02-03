#include <iostream>
#include <stack>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    string str;
    cin >> str;
    stack<pair<ll, ll> > s;
    ll ans = 0;
    for (int i=0; i<str.length(); i++) {
        if (str[i] == '(') s.push(p(0, '('));
        else {
            ll temp = 0;
            while (s.top().first) {
                temp += s.top().second;
                s.pop();
            }
            s.pop(); // '(' pop
            if (!temp) s.push(p(1, 1)); // 레이저 개수
            else s.push(p(1, temp));
            if (temp) ans += (temp+1); // 인접쌍이 아니면
        }
    }
    cout << ans << '\n';
    return 0;
}
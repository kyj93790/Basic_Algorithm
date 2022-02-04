#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
stack<pair<ll, ll> > s; // height, index

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        ll temp;
        cin >> temp;
        while (!s.empty() && s.top().first < temp) {
            s.pop();
        }
        if (s.empty()) cout << 0 << ' ';
        else cout << s.top().second << ' ';
        s.push(p(temp, i));
    }
    return 0;
}
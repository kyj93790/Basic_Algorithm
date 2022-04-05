#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll n, p, q;
map<ll, ll> m;


ll An(ll i) {
    if (i==0) return 1;
    ll f, r;
    f = i/p; r = i/q;
    if (!m[f]) m[f] = An(f);
    if (!m[r]) m[r] = An(r);
    return (m[f] + m[r]);
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> p >> q;
    m[0] = 1;
    cout << An(n) << '\n';
    return 0;
}
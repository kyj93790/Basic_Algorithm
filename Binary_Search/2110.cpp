#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll n, c;
ll x[202020];
ll dist;

void BS(ll l, ll r) {
    if (l > r) return;
    ll mid = (l+r)/2;
    // 간격을 mid
    ll cnt = 1;
    ll curr = x[0];
    for (ll i=1; i<n; i++) {
        if (x[i] >= curr + mid) {
            cnt++;
            curr = x[i];
        }
    }
    if (cnt >= c) {
        dist = max(dist, mid);
        BS(mid+1, r);
    }
    else BS(l, mid-1);
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n  >> c;
    for (ll i=0; i<n; i++) cin >> x[i];
    sort(x, x+n);
    dist = 1;
    BS(1, 1e9);
    cout << dist << '\n';
    return 0;
}
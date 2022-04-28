#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll n, m;
ll t[101010];
ll ans;

void BS(ll l, ll r) {
    if (l > r) return;
    ll mid = (l+r)/2;
    // mid 초 안에 처리 가능한 사람 수 체크
    ll sum = 0;
    for (ll i=0; i<n; i++) {
        sum += mid/t[i];
    }
    if (sum >= m) {
        ans = mid;
        BS(l, mid-1);
    } else {
        BS(mid+1, r);
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> m;
    for (ll i=0; i<n; i++) cin >> t[i];
    sort(t, t+n);
    BS(t[0], t[n-1]*m);
    cout << ans << '\n';
    return 0;
}
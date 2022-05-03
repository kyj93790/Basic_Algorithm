#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll n;
ll cube[22];
ll ans;
ll a, b;

void daq(ll l, ll w, ll h, ll i) {
    ll cube_len = pow(2, i);
    if (l <= 0 || w <= 0 || h <= 0) return ;
    if (i < 0) {
        cout << -1 << '\n';
        exit(0);
    }
    ll l_x, w_x, h_x;
    ll l_r, w_r, h_r;
    l_x = l/cube_len; l_r = l%cube_len;
    w_x = w/cube_len; w_r = w%cube_len;
    h_x = h/cube_len; h_r = h%cube_len;
    ll want_fill = l_x * w_x * h_x;
    if (want_fill == 0) daq(l, w, h, i-1);
    else {
        if (want_fill > cube[i]) {
            ans += cube[i];
            for (ll j=0; j < want_fill-cube[i]; j++) daq(cube_len, cube_len, cube_len, i-1);
            cube[i] = 0;
        } else {
            cube[i] -= want_fill;
            ans += want_fill;
        }
        daq(l_r, cube_len*w_x, cube_len*h_x, i-1);
        daq(cube_len*l_x, w_r, cube_len*h_x, i-1);
        daq(l_r, w_r, cube_len*h_x, i-1);
        daq(l, w, h_r, i-1);
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll l, w, h;
    cin >> l >> w >> h;
    cin >> n;
    for (ll i=0; i<n; i++) {
        cin >> a >> b;
        cube[a] = b;
    }
    daq(l, w, h, n-1);
    cout << ans << '\n';
    return 0;
}
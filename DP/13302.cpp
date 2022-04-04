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
ll dp[111][50]; // x일에 쿠폰이 y개 일 때 minimum 가격
ll un[111];
#define INF 1e9

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> m;
    for (ll i=0; i<m; i++) {
        ll temp;
        cin >> temp;
        un[temp] = 1;
    };
    for (ll i=0; i<n+5; i++) {
        for (ll j=0; j<50; j++) dp[i][j] = INF;
    }
    dp[0][0] = 0;
    for (ll x=1; x<n+5; x++) {
        for (ll y=0; y<50; y++) {
            ll temp = dp[x-1][y] + 10000;
            if (un[x]) temp = min(temp, dp[x-1][y]);
            if (x-3 >= 0 && y-1 >= 0) temp = min(temp, dp[x-3][y-1] + 25000);
            if (x-5 >= 0 && y-2 >= 0) temp = min(temp, dp[x-5][y-2] + 37000);
            if (x-1 >= 0 && y+3 < 50) temp = min(temp, dp[x-1][y+3]);
            dp[x][y] = temp;
        }
    }
    ll ans = INF;
    for (ll i=n; i<n+5; i++) {
        for (ll j=0; j<50; j++) {
            ans = min(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}
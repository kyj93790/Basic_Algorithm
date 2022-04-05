#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)
#define min3(a, b, c) min(a, (ll)min(b, c))
typedef long long ll;
ll n, m;
char map[1010][1010];
ll dp[1010][1010];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> m;
    for (ll i=1; i<=n; i++) {
        for (ll j=1; j<=m; j++) {
            cin >> map[i][j];
        }
    }
    ll ans = 0;
    for (ll i=1; i<=n; i++) {
        for (ll j=1; j<=m; j++) {
            if (map[i][j] == '0') {
                dp[i][j] = 0;
            } else {
                dp[i][j] = 1 + min3(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans*ans << '\n';
    return 0;
}
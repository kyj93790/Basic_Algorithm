#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll n, k;
ll coin[111];
ll dp[10101];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> k;
    for (ll i=0; i<n; i++) cin >> coin[i];
    dp[0] = 1;
    for (ll i=0; i<n; i++) {
        for (ll j=coin[i]; j<=k; j++) {
            dp[j] += dp[j-coin[i]];
        }
    }
    cout << dp[k] << '\n';
    return 0;
}
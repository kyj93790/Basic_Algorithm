#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
string a, b;
ll dp[4040][4040];
ll ans;

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> a >> b;
    for (ll i=1; i<=a.size(); i++) {
        for (ll j=1; j<=b.size(); j++) {
            char x, y;
            x = a[i-1]; y = b[j-1];
            if (x == y) dp[i][j] += (dp[i-1][j-1] + 1);
            else dp[i][j] = 0;
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}
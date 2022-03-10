#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)
#define MAX(a, b, c) max(max(a, b), c)

typedef long long ll;
ll n, m;
ll maze[1010][1010];
ll ans[1010][1010];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> m;
    for (ll i=1; i<=n; i++) {
        for (ll j=1; j<=m; j++) {
            cin >> maze[i][j];
        }
    }
    for (ll i=1; i<=n; i++) {
        for (ll j=1; j<=m; j++) {
            ans[i][j] = MAX(ans[i-1][j], ans[i-1][j-1], ans[i][j-1])+maze[i][j];
        }
    }
    cout << ans[n][m] << '\n';
    return 0;
}
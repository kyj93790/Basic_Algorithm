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
char A[55][55];
char B[55][55];

void reverse(char A[55][55], ll r, ll c) {
    for (ll i=r; i<r+3; i++) {
        for (ll j=c; j<c+3; j++) {
            if (A[i][j] == '0') A[i][j] = '1';
            else A[i][j] = '0';
        }
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> m;
    for (ll i=0; i<n; i++) {
        for (ll j=0; j<m; j++) cin >> A[i][j];
    }
    for (ll i=0; i<n; i++) {
        for (ll j=0; j<m; j++) cin >> B[i][j];
    }
    ll ans = 0;
    for (ll i=0; i<n; i++) {
        for (ll j=0; j<m; j++) {
            if (A[i][j] != B[i][j]) {
                if (i+3 > n || j+3 > m) {
                    cout << -1 << '\n';
                    return 0;
                }
                reverse(A, i, j);
                ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
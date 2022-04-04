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
ll input[55][55];
ll sum[55][55];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> m;
	for (ll i=1; i<=n; i++) {
		for (ll j=1; j<=m; j++) {
			char x;
			cin >> x;
			input[i][j] = x-'0';
			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + input[i][j];
		}
	}
	ll ans = 0, s1, s2, s3, s4;
	// (i, j)를 기준으로 4등분
	for (ll i=1; i<n; i++) {
		for (ll j=1; j<m; j++) {
			ll temp;
			s1 = sum[i][j];
			s2 = sum[i][m] - s1;
			s3 = sum[n][j] - s1;
			s4 = sum[n][m] - s1 - s2 - s3;
			temp = max(s1*(s2+s4)*s3, s1*(s3+s4)*s2);
			ans = max(ans, temp);
		}
	}
	for (ll i=1; i<n-1; i++) { // 가로로 3개
		s1 = sum[i][m];
		for (ll k=i+1; k<n; k++) {
			s2 = sum[k][m] - s1;
			s3 = sum[n][m] - s1 - s2;
			ans = max(ans, s1*s2*s3);
		}
		for (ll j=1; j<m; j++) {
			s2 = sum[n][j] - sum[i][j];
			s3 = sum[n][m] - s1 - s2;
			ans = max(ans, s1*s2*s3);
		}
	}
	for (ll j=1; j<m-1; j++) { // 세로로 3개
		s1 = sum[n][j];
		for (ll k=j+1; k<m; k++) {
			s2 = sum[n][k] - s1;
			s3 = sum[n][m] - s1 - s2;
			ans = max(ans, s1*s2*s3);
		}
		for (ll i=1; i<n; i++) {
			s2 = sum[i][m] - sum[i][j];
			s3 = sum[n][m] - s1 - s2;
			ans = max(ans, s1*s2*s3);
		}
	}
	cout << ans << '\n';
    return 0;
}
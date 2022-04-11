#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll n;
ll len[101010];
ll city[101010];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
	for (ll i=0; i<n-1; i++) cin >> len[i];
	for (ll i=0; i<n; i++) cin >> city[i];
	ll ans = 0;
	ll i, j;
	for (i=0; i<n-1; i=j) { // i 도시에서 사는 것이 이득인 리터 수 세기
		ll temp = 0;
		for (j=i; j<n-1; j++) {
			if (city[i] > city[j]) break;
			temp += len[j];
		}
		ans += temp*city[i];
	}
	cout << ans << '\n';
    return 0;
}
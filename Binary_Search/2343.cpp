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
ll lecture[101010];
ll ans;

void BS(ll l, ll r) {
	if (l > r) return;
	ll mid = (l+r)/2;
	ll cnt = 1;
	ll temp = 0;
	for (ll i=0; i<n; i++) {
		if (temp+lecture[i] > mid) {
			if (cnt == m) {
				BS(mid+1, r);
				return ;
			}
			cnt++;
			temp = lecture[i];
		}
		else temp += lecture[i];
	}
	ans = min(ans, mid);
	BS(l, mid-1);
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> m;
	ll max_time = 0;
	for (ll i=0; i<n; i++) {
		cin >> lecture[i];
		max_time = max(max_time, lecture[i]);
	}
	ans = 1e9;
	BS(max_time, max_time*n);
	cout << ans << '\n';
    return 0;
}
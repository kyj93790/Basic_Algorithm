#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll n, k, m;
vector<ll> v;
ll ans;

void BS(ll l, ll r)
{
	if (l > r) return;
	ll mid = (l+r)/2;
	ll sum = 0;
	for (ll i=0; i<v.size(); i++) {
		sum += v[i]/mid;
	}
	if (sum >= m) {
		ans = mid;
		BS(mid+1, r);
	} else BS(l, mid-1);
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> k >> m;
	ll max_size = 0;
	for(ll i=0; i<n; i++) {
		ll l;
		cin >> l;
		if (l > k) {
			ll temp;
			if (l >= 2*k) temp = l-2*k;
			else temp = l-k;
			v.push_back(temp);
			max_size = max(max_size, temp);
		}
	}
	ans = -1;
	BS(1, max_size);
	cout << ans << '\n';
    return 0;
}
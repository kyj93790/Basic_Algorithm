#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll n, temp;
ll lq[101010];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
	for (ll i=0; i<n; i++) {
		cin >> lq[i];
	}
	sort(lq, lq+n);
	ll l = 0;
	ll r = n-1;
	ll ans = 1e9 * 2;
	ll s, e;
	while (l < r) {
		ll temp =  lq[l] + lq[r];
		if (abs(temp) < ans) {
			s = lq[l]; e = lq[r];
			ans = abs(temp);
			if (temp == 0) break;
		}
		if (temp > 0) {
			r--;
		} else {
			l++;
		}
	}
	cout << s << ' ' << e << '\n';
    return 0;
}
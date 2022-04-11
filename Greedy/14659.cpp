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
ll arr[30303];
ll ans;

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
	for (ll i=0; i<n; i++) {
		cin >> arr[i];
	}
	for (ll i=0; i<n; i++) {
		ll temp = 0;
		for (ll j=i+1; j<n; j++) {
			if (arr[i] < arr[j])
				break ;
			temp++;
		}
		ans = max(ans, temp);
	}
	cout << ans << '\n';
    return 0;
}
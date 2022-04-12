#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll n, ans;
ll arr[55];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
	for (ll i=0; i<n; i++) cin >> arr[i];
	sort(arr, arr+n);
	for (ll i=0; i<n; ) {	// minus part 처리
		if (arr[i] >= 0) break;
		if (i == n-1 || arr[i+1] > 0) {
			ans += arr[i];
			break ;
		}
		else { // minus part에서는 0과 만나면 곱
			ans += arr[i]*arr[i+1];
			i += 2;
		}
	}
	for (ll i=n-1; i>=0; ) { // plus part 처리
		if (arr[i] <= 0) break;
		if (i == 0 || arr[i-1] <= 0) {
			ans += arr[i];
			break ;
		}
		else if (arr[i] == 1 || arr[i-1] == 1) { // 1은 곱하면 손해. 더해야 함.
			ans += arr[i];
			i--;
		}
		else { // plus part에서는 0과 만나면 합
			ans += arr[i]*arr[i-1];
			i -= 2;
		}
	}
	cout << ans << '\n';
    return 0;
}
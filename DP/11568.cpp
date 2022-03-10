#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll n, tmp;
ll dp[1010], input[1010];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
    for (ll i=0; i<n; i++) cin >> input[i];
    // i번째 친구에 대해서
    // 0번째 ~ i-1번째까지 탐색
    // 그 중 i번째 숫자보다 작은 수들을 찾음 -> 여기서 dp 숫자가 큰 값을 추출
    // max + 1 로 갱신
    for (ll i=0; i<n; i++) {
        tmp = 0;
        for (ll j=0; j<i; j++) {
            if (input[j] < input[i]) tmp = max(dp[j], tmp);
        }
        dp[i] = tmp+1;
    }
    ll ans = 0;
    for (ll i=0; i<n; i++) ans = max(ans, dp[i]);
    cout << ans << '\n';
    return 0;
}
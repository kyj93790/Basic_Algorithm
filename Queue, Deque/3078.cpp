#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <map>
#include <deque>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll n, k, temp, ans;
string s;
queue<ll> q;    // 이름의 길이만 넣어줌
ll cnt[22];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> k;
    for (ll i=0; i<n; i++) {
        cin >> s;
        if (q.size() > k) {
            temp = q.front(); q.pop();
            cnt[temp]--;
        }
        ans += cnt[s.size()]++;
        q.push(s.size());
    }
    cout << ans << '\n';
    return 0;
}
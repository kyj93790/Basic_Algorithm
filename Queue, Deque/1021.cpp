#include <iostream>
#include <queue>
#include <deque>
using namespace std;

typedef long long ll;
ll ans;
ll l, r;
deque<ll> q;

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n, m, x;
    cin >> n >> m;
    for (ll i=1; i<=n; i++) { 
        q.push_back(i);
    }
    for (ll i=0; i<m; i++) {
        cin >> x;
        for (ll j=0; j<q.size(); j++) {
            if (q[j] == x) {
                l = j;
                break;
            }
        }
        r = q.size()-l;
        if (l <= r) {
            ans += l;
            while (l--) {
                x = q.front(); q.pop_front();
                q.push_back(x);
            }
        } else {
            ans += r;
            while (r--) {
                x = q.back(); q.pop_back();
                q.push_front(x);
            }
        }
        q.pop_front();
    }
    cout << ans << '\n';
    return 0;
}
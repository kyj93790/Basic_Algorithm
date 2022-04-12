#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll n, a, b, c, d;
typedef struct flower {
    pair<ll, ll> s;
    pair<ll, ll> f;
} flower;
flower flo[101010];

int comp_pair(pair<ll, ll> a, pair<ll, ll> b) {
    if (a.first != b.first) return a.first - b.first;
    else return a.second - b.second;
}

bool comp_flo(flower a, flower b) {
    if (comp_pair(a.s, b.s) != 0) return a.s < b.s;
    else return a.f < b.f;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
    for (ll i=0; i<n; i++) {
        cin >> flo[i].s.first >> flo[i].s.second;
        cin >> flo[i].f.first >> flo[i].f.second;
    }
    sort(flo, flo+n, comp_flo);
    pair<ll, ll> curr, next;
    curr.first = 3;
    curr.second = 1;
    next.first = 3;
    next.second = 1;
    ll ans = 0;
    for (ll i=0; i<n; ) {
        if (comp_pair(curr, flo[i].s) >= 0) {
            if (comp_pair(next, flo[i].f) < 0) {
                next.first = flo[i].f.first;
                next.second = flo[i].f.second;
            }
            if (i == n-1) {
                if (comp_pair(curr, next) == 0) {
                    cout << 0 << '\n';
                    return (0);
                }
                curr.first = next.first;
                curr.second = next.second;
                ans++;
            }
            i++;
        } else {
            if (comp_pair(curr, next) == 0) {
                cout << 0 << '\n';
                return (0);
            }
            curr.first = next.first;
            curr.second = next.second;
            ans++;
            if (curr.first == 12) break;
        }
    }
    if (curr.first != 12) cout << 0 << '\n';
    else cout << ans << '\n';
    return 0;
}
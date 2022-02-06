#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
#define p(a, b) make_pair(a, b)
#define all(v) v.begin(), v.end()

typedef long long ll;

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    vector<pair<ll, ll> > v;
    ll l, h;
    for (int i=0; i<n; i++) {
        cin >> l >> h;
        v.push_back(p(l, h));
    }
    sort(all(v));
    ll max = 0;
    ll max_i = 0, max_j = 0;
    for (int i=0; i<n; i++) {
        l = v[i].first; h = v[i].second;
        if (max < h) {
            max = h;
            max_i = max_j = l;
        }
        else if (max == h) {
            max_j = l;
        }
    }
    ll ans = 0;
    ll prel = v[0].first, preh = v[0].second;
    for (int i=1; i<n; i++) { // 오름차순 체크
        ll currl = v[i].first, currh = v[i].second;
        if (currh > preh) {
            ans += (currl - prel) * preh;
            prel = currl; preh = currh;
            if (currh == max) break;
        }
    }
    prel = v[n-1].first, preh = v[n-1].second;
    for (int i=n-2; i>=0; i--) { // 내림차순 체크
        ll currl = v[i].first, currh = v[i].second;
        if (currh > preh) {
            ans += (prel - currl) * preh;
            prel = currl; preh = currh;
            if (currh == max) break;
        }
    }
    ans += (max_j - max_i + 1)*max;
    cout << ans << '\n';
    return 0;
}
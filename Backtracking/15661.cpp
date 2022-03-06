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
ll s[22][22];
ll start, link;
ll ans;
vector<ll> vs, vl;

void calc_min(ll curr) {
    if (curr >= n) {
        ans = min(ans, abs(start-link));
        return ;
    }
    // start에 넣는 case
    for (ll i=0; i<vs.size(); i++) {
        start += s[vs[i]][curr];
        start += s[curr][vs[i]];
    }
    vs.push_back(curr);
    calc_min(curr+1);
    vs.pop_back();
    for (ll i=0; i<vs.size(); i++) {
        start -= s[vs[i]][curr];
        start -= s[curr][vs[i]];
    }
    // link에 넣는 case
    for (ll i=0; i<vl.size(); i++) {
        link += s[vl[i]][curr];
        link += s[curr][vl[i]];
    }
    vl.push_back(curr);
    calc_min(curr+1);
    vl.pop_back();
    for (ll i=0; i<vl.size(); i++) {
        link -= s[vl[i]][curr];
        link -= s[curr][vl[i]];
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
    ans = 1e9;
    for (ll i=0; i<n; i++) {
        for (ll j=0; j<n; j++) cin >> s[i][j];
    }
    calc_min(0);
    cout << ans << '\n';
    return 0;
}
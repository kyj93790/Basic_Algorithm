#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>
#include <vector>
#define p(a, b) make_pair(a, b)
using namespace std;

typedef long long ll;
ll n;
ll a[1010101];
deque<pair<ll, ll> > q;
vector<pair<ll, ll> > v;

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
    for (ll i=1; i<=n; i++) {
        cin >> a[i];
        q.push_back(p(i, 0));
    }
    pair<ll, ll> temp, x;
    for (ll i=1; i<=n; i++) {
        if (a[i] == 1) {
            x = q.front(); q.pop_front();
        } else if (a[i] == 2) {
            temp = q.front(); q.pop_front();
            x = q.front(); q.pop_front();
            q.push_front(temp);
        } else {
            x = q.back(); q.pop_back();
        }
        x.second = n-i+1;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for (ll i=0; i<v.size(); i++) cout << v[i].second << ' ';
    return 0;
}
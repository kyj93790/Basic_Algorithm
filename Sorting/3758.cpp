#include <iostream>
using namespace std;

typedef long long ll;

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll T;
    cin >> T;
    while (T--) {
        ll n, k, t, m;
        ll score[101][101] = {0, };
        ll sum[101] = {0, };
        ll tries[101] = {0, };
        ll lastlog[101] = {0, };
        cin >> n >> k >> t >> m;
        for(int a=1; a<=m; a++) {
            ll i, j, s;
            cin >> i >> j >> s;
            if (score[i][j] < s) {
                sum[i] = sum[i] - score[i][j] + s;
                score[i][j] = s;
            }
            tries[i]++;
            lastlog[i] = a;
        }
        ll rating = 1;
        for (int a=1; a<=n; a++) {
            if (a == t) continue;
            if (sum[a] > sum[t]) rating++;
            else if (sum[a] == sum[t] && tries[a] < tries[t]) rating++;
            else if (sum[a] == sum[t] && tries[a] == tries[t] && lastlog[a] < lastlog[t]) rating++;
        }
        cout << rating << '\n';
    }
    return 0;
}
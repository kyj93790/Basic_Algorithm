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
ll a[12], x[4], cnt[4];
ll ans_min = 1e9, ans_max=-1e9;
vector<int> v;
vector<int> op;

void bt(int curr) {
    if (curr >= n-1) {
        ll res = v[0];
        for (int i=0; i<op.size(); i++) {
            if (op[i] == 0) { // 덧셈
                res += v[i+1];
            } else { // 뺄셈
                res -= v[i+1];
            }
        }
        ans_min = min(ans_min, res);
        ans_max = max(ans_max, res);
        return ;
    }
    // a[curr]와 a[curr+1] 사이의 연산자를 결정
    for (int i=0; i<4; i++) {
        if (cnt[i] < x[i]) { // 아직 해당 연산자가 남아있다면 가능
            cnt[i]++;
            if (i==2) { // 곱셈
                ll prev = v[v.size()-1];
                v[v.size()-1] *= a[curr+1];
                bt(curr+1);
                v[v.size()-1] = prev;
            } else if (i==3) { // 나눗셈
                ll prev = v[v.size()-1];
                v[v.size()-1] /= a[curr+1];
                bt(curr+1);
                v[v.size()-1] = prev;
            } else {
                op.push_back(i);
                v.push_back(a[curr+1]);
                bt(curr+1);
                v.pop_back();
                op.pop_back();
            }
            cnt[i]--;
        }
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i]; // A[i]
    for (int i=0; i<4; i++) cin >> x[i]; // 연산자 갯수
    v.push_back(a[0]);
    bt(0);
    cout << ans_max << '\n' << ans_min << '\n';
    return 0;
}
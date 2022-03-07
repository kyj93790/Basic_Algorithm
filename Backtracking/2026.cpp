#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll k, n, f, a, b;
bool bf[909][909];
vector<ll> v;

int bt(int curr) {
    if (v.size() >= k) return 1;
    if (curr > n) return 0;
    // 현재까지의 후보군과 남은 학생을 합쳐도 k가 안되는 경우
    if (n-curr+1 + v.size() < k) return 0;
    // 지금까지 후보군과 모두 친구인지 check
    bool check = true;
    for (int i=0; i<v.size(); i++) {
        if (!bf[v[i]][curr]) check = false;
    }
    if (check) {
        v.push_back(curr);
        if (bt(curr+1)) return 1;
        v.pop_back();
    }
    // 제외하고 다음 친구 확인
    if (bt(curr+1)) return 1;
    return 0;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> k >> n >> f;
    for (int i=0; i<f; i++) {
        cin >> a >> b;
        bf[a][b] = bf[b][a] = true;
    }
    if (!bt(1)) cout << -1 << '\n';
    else {
        for (int i=0; i<k; i++) {
            cout << v[i] << '\n';
        }
    }
    return 0;
}
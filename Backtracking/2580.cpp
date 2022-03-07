#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
vector<pair<ll, ll> > v;
int sdk[9][9];

int bt(int curr) {
    if (curr == v.size()) return 1;
    int r = v[curr].first, c = v[curr].second;
    int visit[10] = {0, };
    // 내 기준 가로, 세로에 있는 숫자 체크
    for (int i=0; i<9; i++) {
        visit[sdk[i][c]] = 1;
        visit[sdk[r][i]] = 1;
    }
    // 같은 box 내에 있는 숫자 체크
    int x=r/3*3, y=c/3*3;
    for (int i=x; i<x+3; i++) {
        for (int j=y; j<y+3; j++) {
            visit[sdk[i][j]] = 1;
        }
    }
    for (int i=1; i<=9; i++) {
        if (visit[i]) continue;
        sdk[r][c] = i;
        if (bt(curr+1)) return 1;
        sdk[r][c] = 0;
    }
    return 0;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cin >> sdk[i][j];
            if (sdk[i][j] == 0) v.push_back(p(i, j));
        }
    }
    bt(0);
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cout << sdk[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
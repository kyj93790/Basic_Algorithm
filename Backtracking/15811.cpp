#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
string a, b, c;
vector<char> v;
int num[10], alpha[26];
map<char, int> m;

int check_num(int curr, int up) {
    int na=0, nb=0, nc=0;
    int ai, bi, ci;
    ai = a.size()-curr; bi = b.size()-curr; ci = c.size()-curr;
    if (ai < 0 && bi < 0 && ci < 0) {
        if (up == 0) return 1;
        else return 0;
    }
    if (ai >= 0) na = m[a[ai]];
    if (bi >= 0) nb = m[b[bi]];
    if (ci >= 0) nc = m[c[ci]];
    if ((na+nb+up) % 10 != nc) return 0;
    return check_num(curr+1, (na+nb+up)/10);
}

int bt(int curr) {
    if (curr >= v.size()) {
        return check_num(1, 0);
    }
    for (int i=0; i<10; i++) {
        if (num[i]) continue;
        num[i] = 1;
        m[v[curr]] = i;
        if (bt(curr+1)) return 1;
        num[i] = 0;
        m[v[curr]] = -1;
    }
    return 0;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> a >> b >> c;
    ll tmp;
    for (int i=0; i<a.size(); i++) {
        tmp = a[i]-'A';
        if (!alpha[tmp]) {
            v.push_back(a[i]);
            alpha[tmp] = 1;
        }
    }
    for (int i=0; i<b.size(); i++) {
        tmp = b[i]-'A';
        if (!alpha[tmp]) {
            v.push_back(b[i]);
            alpha[tmp] = 1;
        }
    }
    for (int i=0; i<c.size(); i++) {
        tmp = c[i]-'A';
        if (!alpha[tmp]) {
            v.push_back(c[i]);
            alpha[tmp] = 1;
        }
    }
    if (bt(0)) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
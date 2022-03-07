#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll k, s;
char tmp;
vector<char> v;
bool visit[10], visit2[10];
vector<int> ans, ans2;

int maxbt(ll curr) {
    if (curr == k) {
        for (ll i=0; i<ans.size(); i++) {
            cout << ans[i];
        }
        cout << '\n';
        return 1;
    }
    for (ll i=9; i>=0; i--) {
        if (visit[i]) continue;
        if (v[curr] == '<') {
            if (ans[ans.size()-1] < i) {
                ans.push_back(i);
                visit[i] = true;
                if (maxbt(curr+1)) return 1;
                ans.pop_back();
                visit[i] = false;
            }
        } else {
            if (ans[ans.size()-1] > i) {
                ans.push_back(i);
                visit[i] = true;
                if (maxbt(curr+1)) return 1;
                ans.pop_back();
                visit[i] = false;
            }
        }
    }
    return 0;
}

int minbt(ll curr) {
    if (curr == k) {
        for (ll i=0; i<ans2.size(); i++) {
            cout << ans2[i];
        }
        cout << '\n';
        return 1;
    }
    for (ll i=0; i<10; i++) {
        if (visit2[i]) continue;
        if (v[curr] == '<') {
            if (ans2[ans2.size()-1] < i) {
                ans2.push_back(i);
                visit2[i] = true;
                if (minbt(curr+1)) return 1;
                ans2.pop_back();
                visit2[i] = false;
            }
        } else {
            if (ans2[ans2.size()-1] > i) {
                ans2.push_back(i);
                visit2[i] = true;
                if (minbt(curr+1)) return 1;
                ans2.pop_back();
                visit2[i] = false;
            }
        }
    }
    return 0;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> k;
    for (ll i=0; i<k; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    for (ll i=9; i>=0; i--) {
        ans.push_back(i);
        visit[i] = true;
        if (maxbt(0)) break;
        ans.pop_back();
        visit[i] = false;
    }
    for (ll i=0; i<10; i++) {
        ans2.push_back(i);
        visit2[i] = true;
        if (minbt(0)) break;
        ans2.pop_back();
        visit2[i] = false;
    }
    return 0;
}
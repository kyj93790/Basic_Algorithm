#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
int n, len;
vector<int> v;
char s[11][11];
ll linesum[11];

int bt(int curr) {
    if (curr >= n) return 1;
    // 현재 위치에 대해 값을 하나씩 넣어봄
    for (int i=-10; i<=10; i++) {
        // 이제까지의 linesum 조건을 모두 만족시켜야만 다음 단계로 진행
        bool check = true;
        for (int j=0; j<=curr; j++) {
            if (s[j][curr]=='-' && i+linesum[j]>=0) {
                check = false;
            } else if (s[j][curr] == '0' && i+linesum[j]!=0) {
                check = false;                 
            } else if (s[j][curr] == '+' && i+linesum[j]<=0) {
                check = false;
            }
        }
        if (check) {
            v.push_back(i);
            for (int j=0; j<=curr; j++) {
                linesum[j] += i;
            }
            if (bt(curr+1)) return 1;
            for (int j=0; j<=curr; j++) {
                linesum[j] -= i;
            }
            v.pop_back();
        }
    }
    return 0;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
    len = n*(n+1)/2;
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            cin >> s[i][j];
        }
    }
    bt(0);
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << ' ';
    } cout << '\n';
    return 0;
}
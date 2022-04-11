#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll n, m;

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> m;
    if (n==1)
        cout << 1 << '\n';
    else if (n==2) {
        if (m<7) cout << (m+1)/2 << '\n';
        else cout << 4 << '\n';
    }
    else if (m <= 3) cout << m << '\n';
    else if (m <= 6) cout << 4 << '\n';
    else cout << 3 + (m-5) << '\n';
    return 0;
}
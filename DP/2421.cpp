#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <math.h>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
bool prime[1000000];
ll dp[1000][1000];
ll n;

void setprime(void) {
    memset(prime, 1, sizeof(prime));
    prime[0] = prime[1] = false;
    for (ll i=2; i<=sqrt(1000000); i++) {
        if (prime[i]) {
            for (ll j=i*i; j<=1000000; j+=i) prime[j] = false;
        }
    }
}

bool checkprime(ll a, ll b) {
    ll digit = 1;
    while (b / digit) {
        digit*=10;
    }
    ll c = a*digit + b;
    return prime[c];
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
    ll total=2;
    ll i, j;
    setprime();
    while (total <= 2*n) {
        total++;
        for (i=1, j=total-1; i<total; i++, j--) {
            if (i > n || j > n) continue;
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (checkprime(i, j)) dp[i][j]++;
        }
    }
    cout << dp[n][n] << '\n';
    return 0;
}
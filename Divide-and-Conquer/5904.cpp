#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll n;

ll cnt(ll i)
{
	if (i < 0) return 0;
	if (i == 0) return 3;
	return cnt(i-1)*2 + i+3;
}

void daq(ll i)
{
	ll prev;
	prev = cnt(i-1);
	if (n <= prev) {
		daq(i-1);
	} else if (prev + 1 == n) {
		cout << "m\n";
		return ;
	} else if (n <= prev + i + 3) {
		cout << "o\n";
		return ;
	} else {
		n -= (prev + i + 3);
		daq(i-1);
	} 
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
	daq(29);
    return 0;
}
#include <iostream>
using namespace std;

typedef long long ll;
ll w[1010101];

void merge(ll l, ll m, ll r) {
    ll i=l, j=m+1, k=0;
    ll *temp = new ll[r-l+1];
    while (i<=m && j<=r) {
        if (w[i] <= w[j]) {
            temp[k++] = w[i++];
        }
        else {
            temp[k++] = w[j++];
        }
    }
    while (i<=m) temp[k++] = w[i++];
    while (j<=r) temp[k++] = w[j++];
    for (k=0; k<r-l+1; k++) {
        w[l+k] = temp[k];
    }
    delete[] temp;
}

void mergeSort(ll l, ll r) {
    if (l < r) {
        ll m = (l + r)/2;
        mergeSort(l, m);
        mergeSort(m+1, r);
        merge(l, m, r);
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    for (ll i=0; i<n; i++){
        cin >> w[i];
    }
    mergeSort(0, n-1);
    ll sum = 0;
    for (ll i=0; i<n; i++) {
        if (w[i] > sum + 1) break;
        sum += w[i];
    }
    cout << sum + 1 << '\n';
    return 0;
}
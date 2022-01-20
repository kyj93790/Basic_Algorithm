#include <iostream>
using namespace std;

typedef long long ll;

void merge(ll *note, ll l, ll m, ll r) {
    ll i=l, j=m+1, k=0;
    ll *temp = new ll[r-l+1];
    while (i<=m && j<=r) {
        if (note[i] <= note[j]) {
            temp[k++] = note[i++];
        }
        else {
            temp[k++] = note[j++];
        }
    }
    while (i<=m) temp[k++] = note[i++];
    while (j<=r) temp[k++] = note[j++];
    for (k=0; k<r-l+1; k++) {
        note[l+k] = temp[k];
    }
    delete[] temp;
}

void mergeSort(ll *note, ll l, ll r) {
    if (l < r) {
        ll m = (l + r)/2;
        mergeSort(note, l, m);
        mergeSort(note, m+1, r);
        merge(note, l, m, r);
    }
}

int BinarySearch(ll *note, ll l, ll r, ll key) {
    if (l <= r) {
        ll m = (l + r)/2;
        if (note[m] == key) return 1;
        else if (note[m] < key) return BinarySearch(note, m+1, r, key);
        else return BinarySearch(note, l, m-1, key);
    }
    else return 0;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll *note = new ll[n];
        for (ll i=0; i<n; i++) {
            cin >> note[i];
        }
        mergeSort(note, 0, n-1);
        ll m;
        cin >> m;
        for (ll i=0; i<m; i++) {
            ll x;
            cin >> x;
            cout << BinarySearch(note, 0, n-1, x) << '\n';
        }
        delete[] note;
    }
    return 0;
}
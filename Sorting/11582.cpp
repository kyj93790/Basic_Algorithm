#include <iostream>
using namespace std;

typedef long long ll;
ll n, k;

void merge(ll *arr, ll l, ll m, ll r) {
    ll *temp = new ll[r - l + 1];
    ll i=l, j=m+1, k=0;
    while(i<=m && j<=r) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while (i<=m) temp[k++] = arr[i++];
    while (j<=r) temp[k++] = arr[j++];
    for (k=0; k<r-l+1; k++) arr[l+k] = temp[k];
}

void mergeSort(ll *arr, ll l, ll r) {
    if (l < r) {
        ll m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        if (r - l + 1 <= n/k)
            merge(arr, l, m, r);
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
    ll *arr = new ll[n];
    for (int i=0; i<n; i++) cin >> arr[i];
    cin >> k;
    mergeSort(arr, 0, n-1);
    for (int i=0; i<n; i++) cout << arr[i] << ' ';
    cout << '\n';
    return 0;
}
#include <iostream>
using namespace std;

typedef long long ll;
ll A[20202], B[20202];

void merge(ll *arr, ll l, ll m, ll r) {
    ll i=l, j=m+1, k=0;
    ll *temp = new ll[r-l+1];
    while (i<=m && j<=r) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }
    while (i<=m) temp[k++] = arr[i++];
    while (j<=r) temp[k++] = arr[j++];
    for (k=0; k<r-l+1; k++) {
        arr[l+k] = temp[k];
    }
    delete[] temp;
}

void mergeSort(ll *arr, ll l, ll r) {
    if (l < r) {
        ll m = (l + r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        int i,j;
        for (i=0; i<n; i++) cin >> A[i];
        for (i=0; i<m; i++) cin >> B[i];
        mergeSort(A, 0, n-1);
        mergeSort(B, 0, m-1);
        ll curr = 0;
        ll sum = 0;
        for (i=0; i<n; i++) {
            for (j=curr; j<m; j++) {
                if (B[j] >= A[i]) break;
            }
            sum += j;
            curr = j;
        }
        cout << sum << '\n';
    }
    return 0;
}
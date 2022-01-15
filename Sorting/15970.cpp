#include <iostream>
using namespace std;

typedef long long ll;
typedef struct point {
    ll x;
    ll c;
} point;

int cmpPoint(point a, point b) {
    if (a.c != b.c) return (a.c - b.c);
    else return (a.x - b.x);
}

void merge(point *arr, ll l, ll m, ll r) {
    point *temp = new point[r-l+1];
    ll i = l, j = m+1, k = 0;
    while (i<=m && j<=r) {
        if (cmpPoint(arr[i], arr[j]) <= 0) {
            temp[k++] = arr[i++];
        }
        else temp[k++] = arr[j++];
    }
    while (i<=m) temp[k++] = arr[i++];
    while (j<=r) temp[k++] = arr[j++];
    for (k=0; k<r-l+1; k++) arr[l+k] = temp[k];
    delete[] temp;
}

void mergeSort(point *arr, ll l, ll r) {
    if (l < r) {
        ll m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    point *arr = new point[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i].x >> arr[i].c;
    }
    mergeSort(arr, 0, n-1);
    ll sum = 0;
    for (int i=0; i<n; i++) {
        ll temp = 101010;
        if (i > 0 && arr[i-1].c == arr[i].c && arr[i].x - arr[i-1].x < temp) {
            temp = arr[i].x - arr[i-1].x;
        }
        if (i < n-1 && arr[i].c == arr[i+1].c && arr[i+1].x - arr[i].x < temp) {
            temp = arr[i+1].x - arr[i].x;
        }
        sum += temp;
    }
    cout << sum << '\n';
    return 0;
}
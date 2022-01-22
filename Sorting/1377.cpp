#include <iostream>
using namespace std;

typedef long long ll;
typedef struct node {
    ll val;
    ll index;
} node;
node A[505050];

void merge(node *arr, ll l, ll m, ll r) {
    node *temp = new node[r - l + 1];
    ll i=l, j=m+1, k=0;
    while(i<=m && j<=r) {
        if (arr[i].val <= arr[j].val) {
            temp[k].val = arr[i].val;
            temp[k++].index = arr[i++].index;
        }
        else {
            temp[k].val = arr[j].val;
            temp[k++].index = arr[j++].index;
        }
    }
    while (i<=m) {
        temp[k].val = arr[i].val;
        temp[k++].index = arr[i++].index;
    }
    while (j<=r) {
        temp[k].val = arr[j].val;
        temp[k++].index = arr[j++].index;
    }
    for (k=0; k<r-l+1; k++) {
        arr[l+k].val = temp[k].val;
        arr[l+k].index = temp[k].index;
    }
    delete[] temp;
}

void mergeSort(node *arr, ll l, ll r) {
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
    for (int i=1; i<=n; i++) {
        cin >> A[i].val;
        A[i].index = i;
    }
    mergeSort(A, 1, n);
    ll max = 0;
    for (int i=1; i<=n; i++) {
        ll temp = A[i].index - i;
        if (max < temp) max = temp;
    }
    cout << max+1 << '\n';
    return 0;
}
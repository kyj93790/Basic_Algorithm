#include <iostream>
using namespace std;

void mergeSort(int *arr, int i, int j);

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n-1);
    for (int i=0; i<n; i++) cout << arr[i] << '\n';
    return 0;
}

void merge(int *arr, int s, int m, int e) {
    int *temp = new int[e-s+1];
    int i = s, j = m+1;
    int k = 0;
    while (i <= m && j <= e) {
        if (arr[i] >= arr[j])
            temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while (i<=m) temp[k++] = arr[i++];
    while (j<=e) temp[k++] = arr[j++];
    for (k = 0; k<e-s+1; k++) {
        arr[s+k] = temp[k];
    }
}

void mergeSort(int *arr, int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        mergeSort(arr, s, m);
        mergeSort(arr, m+1, e);
        merge(arr, s, m, e);
    }
}
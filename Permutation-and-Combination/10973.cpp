#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int n;
    cin >> n;

    int *arr;
    arr = new int[n];
    for (int i=0; i<n; i++)
        cin >> arr[i];
    int found = 0;
    for (int i=n-2; i>=0; i--){
        if (arr[i] > arr[i+1]) {
            found = 1;
            int max = arr[i+1];
            int max_i = i+1;
            for (int j=i+2; j<n; j++) {
                if (arr[i] > arr[j] && max < arr[j]) {
                    max = arr[j];
                    max_i = j;
                }
            }
            swap(&arr[i], &arr[max_i]);
            for (int j=i+1; j<n-1; j++) {
                for (int k=j+1; k<n; k++) {
                    if (arr[j] < arr[k])
                        swap(&arr[j], &arr[k]);
                }
            }
            break ;
        }
    }
    if (!found) cout << -1 << '\n';
    else {
        for (int i=0; i<n; i++)
            cout << arr[i] << ' ';
        cout << '\n';
    }
    return (0);
}
#include <iostream>
using namespace std;

int main(void) {
    int n;
    int h[50];
    int w[50];

    cin >> n;
    for (int i=0; i<n; i++)
        cin >> h[i] >> w[i];

    for (int i=0; i<n; i++) {
        int rate = 1;
        for (int j=0; j<n; j++) {
            if (i == j) continue;
            if (h[j] > h[i] && w[j] > w[i]) rate++;
        }
        cout << rate;
        if (i == n-1) cout << '\n';
        else cout << ' ';
    }
    return (0);
}
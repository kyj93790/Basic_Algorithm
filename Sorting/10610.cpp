#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
int arr[10];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    char temp;
    int sum = 0;
    int max = 0;
    while (cin >> temp) {
        arr[temp - '0']++;
        sum += (temp - '0');
        if (temp-'0' > max) max = temp - '0';
    }
    if (sum%3!=0 || !arr[0]) cout << -1 << '\n';
    else {
        for (int i=max; i>=0; i--) {
            for (int j=arr[i]; j>0; j--) {
                cout << i;
            }
        }
        cout << '\n';
    }
    return 0;
}
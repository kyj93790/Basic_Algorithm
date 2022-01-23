#include <iostream>
using namespace std;

typedef long long ll;
int cnt[10101];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int max = 0;
    while (n--) {
        int temp;
        cin >> temp;
        cnt[temp]++;
        if (max < temp) max = temp;
    }
    for (int i=0; i<=max; i++) {
        for (int j=cnt[i]; j>0; j--) {
            cout << i << '\n';
        }
    }
    return 0;
}
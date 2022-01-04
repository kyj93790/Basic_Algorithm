#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

void sequence(int n, int m, int i) {
    if (i == m + 1) {
        for (int j=0; j<m-1; j++)
            cout << v[j] << ' ';
        cout << v[m-1] << '\n';
    }
    else if (i > n) return ;
    for (int j=1; j<=n; j++) {
        v.push_back(j);
        sequence(n, m, i+1);
        v.pop_back();
    }
}

int main(void) {
    int n, m;
    cin >> n >> m;
    sequence(n, m, 1);
    return (0);
}
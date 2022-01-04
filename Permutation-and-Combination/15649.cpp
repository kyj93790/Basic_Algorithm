#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int visit[9];

void sequence(int n, int m, int i) {
    if (i == m + 1) {
        for (int j=0; j<m-1; j++)
            cout << v[j] << ' ';
        cout << v[m-1] << '\n';
        return ;
    }
    else if (i > n) return ;
    for (int j=1; j<=n; j++) {
        if (visit[j] == 0) {
            v.push_back(j);
            visit[j] = 1;
            sequence(n, m, i+1);
            v.pop_back();
            visit[j] = 0;
        }
    }
}

int main(void) {
    int n, m;
    cin >> n >> m;
    for (int i=1; i<9; i++) visit[i] = 0;
    sequence(n, m, 1);
    return (0);
}
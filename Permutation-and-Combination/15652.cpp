#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;

void sequence(int i) {
    if (v.size() == m) {
        for (int j=0; j<m-1; j++)
            cout << v[j] << ' ';
        cout << v[m-1] << '\n';
        return ;
    }
    for (int j=i; j<=n; j++) {
        v.push_back(j);
        sequence(j);
        v.pop_back();
    }
}

int main(void) {
    cin >> n >> m;
    sequence(1);
    return (0);
}
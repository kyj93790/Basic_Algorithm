#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

void sequence(int n, int m, int i) {
    if (v.size() == m) {
        for (int j=0; j<m-1; j++)
            cout << v[j] << ' ';
        cout << v[m-1] << '\n';
        return ;
    }
    else if (i > n) return ;
    v.push_back(i);
    sequence(n, m, i+1);
    v.pop_back();
    sequence(n, m, i+1);
}

int main(void) {
    int n, m;
    cin >> n >> m;
    sequence(n, m, 1);
    return (0);
}
#include <iostream>
#include <vector>
using namespace std;

void sequence(int n);
vector<int> v;
int visit[10];

int main(void) {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) visit[i] = 0;
    sequence(n);
    return (0);
}

void sequence(int n) {
    if (v.size() == n) {
        for (int i=0; i<n; i++)
            cout << v[i] << ' ';
        cout << '\n';
        return ;
    }
    for (int i=1; i<=n; i++){
        if (visit[i] == 0) {
            v.push_back(i);
            visit[i] = 1;
            sequence(n);
            v.pop_back();
            visit[i] = 0;
        }
    }
}
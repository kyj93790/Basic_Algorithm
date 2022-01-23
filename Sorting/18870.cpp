#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
vector<int> origin;
vector<int> v;

int BinarySearch(int l, int r, int key) {
    if (l <= r) {
        int m = (l + r)/2;
        if (v[m] == key) return (m);
        else if (v[m] < key) return BinarySearch(m+1, r, key);
        else return BinarySearch(l, m-1, key);
    }
    return (-1);
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
        origin.push_back(temp);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i=0; i<origin.size(); i++) cout << BinarySearch(0, v.size()-1, origin[i]) << ' ';
    cout << '\n';
}
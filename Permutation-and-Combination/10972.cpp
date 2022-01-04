#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b) {
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    vector<int> v;
    int n;

    cin >> n;
    for (int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    int found = 0;
    for (int i=v.size()-2; i>=0; i--) {
        if (v[i] < v[i + 1]) {
            found = 1;
            int min = v[i+1];
            int min_i = i+1;
            for (int j=i+2; j<v.size(); j++) {
                if (v[j] > v[i] && min > v[j]) {
                    min = v[j];
                    min_i = j;
                }
            }
            swap(&v[i], &v[min_i]);       
            for (int j=i+1; j<v.size()-1; j++) {
                for (int k=j+1; k<v.size(); k++) 
                    swap(&v[j], &v[k]);
            }
            break ;
        }
    }
    if (!found) cout << -1 << '\n';
    else {
        for (int i=0; i<v.size(); i++)
            cout << v[i] << ' ';
        cout << '\n';
    }
    return (0);
}
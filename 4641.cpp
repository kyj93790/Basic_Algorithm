#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    while (1)
    {
        vector<int> v;
        int count;
        while (1)
        {
            int e;
            cin >> e;
            if (e == -1) return (0);
            if (e == 0) break ;
            v.push_back(e);
        }
        count = 0;
        for(int i=0; i<v.size(); i++) {
            for (int j=0; j<v.size(); j++) {
                if (v[i] * 2 == v[j]) {
                    count++;
                    break ;
                }
            }
        }
        cout << count << '\n';
    }
    return (0);
}
#include <iostream>
using namespace std;

int divided(int i)
{
    int s = 0;

    while (i > 0) {
        s += (i % 10);
        i /= 10;
    }
    return (s);
}

int main(void){
    int n;
    cin>>n;

    int c = 0;
    for (int i=1; i<n; i++){
        if (i + divided(i) == n){
            c = i;
            break ;
        }
    }
    cout << c << '\n';
    return (0);
}
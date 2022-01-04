#include <iostream>
using namespace std;

int check_num(int n) {
    if (n / 10 == 0) return (1);
    int d = n / 10 % 10 - n % 10;
    n /= 10;
    while (n / 10 > 0) {
        if (n / 10 % 10 - n % 10 != d) return (0);
        n /= 10;
    }
    return (1);
}

int main(void){
    int n;
    cin >> n;

    int count = 0;
    for (int i=1; i<=n; i++){
        if (check_num(i)) count++;
    }
    cout << count << '\n';
    return (0);
}
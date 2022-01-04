#include <iostream>
using namespace std;

int check_num (int x) {
    int max = 0;
    int succesive6 = 0;
    while (x > 0) {
        if (x % 10 == 6) succesive6++;
        else {
            if (max < succesive6)
                max = succesive6;
            succesive6 = 0;
        }
        x /= 10;
    }
    if (max < succesive6)
        max = succesive6;
    if (max >= 3) return (1);
    else return (0);
}

int main(void) {
    int n;
    cin >> n;

    long long i = 665;
    int count = 0;
    while (1) {
        if (check_num(i)) count++;
        if (count == n) break;
        i++;
    }
    cout << i << '\n';
    return (0);
}
#include <iostream>
using namespace std;

int reverse_num(int curr)
{
    int result;
    
    result = 0;
    while (curr > 0)
    {
        result = result * 10 + (curr % 10);
        curr /= 10;
    }
    return (result);
}

int main(void)
{
    int n, k;
    int max;
    
    cin >> n >> k;
    max = 0;
    for (int i=1; i<= k; i++)
    {
        int rev = reverse_num(n*i);
        if (rev > max)
            max = rev;
    }
    cout << max << '\n';
    return (0);
}
#include <iostream>
#include <stack>
using namespace std;

typedef long long ll;
ll alpha[26];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n;
    string str;
    cin >> n >> str;
    double ans = 0;
    stack<double> s;
    for (int i=0; i<str.length(); i++) {
        if ('A' <= str[i] && str[i] <= 'Z') {
            if (!alpha[str[i] - 'A']) {
                cin >> alpha[str[i] - 'A'];
            }
            s.push(alpha[str[i] - 'A']);
        }
        else {
            double a, b;
            b = s.top(); s.pop();
            a = s.top(); s.pop();
            if (str[i] == '*') s.push(a*b);
            else if (str[i] == '+') s.push(a+b);
            else if (str[i] == '/') s.push(a/b);
            else s.push(a-b);
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << s.top() << '\n';
    return 0;
}
#include <iostream>
#include <stack>
using namespace std;

typedef long long ll;

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        stack<char> s;
        bool ans = true;
        for (int i=0; i<str.length(); i++) {
            if (str[i] == '(') s.push('(');
            else {
                if (s.empty() || s.top() == ')') {
                    ans = false;
                    break;
                } 
                else s.pop();
            }
        }
        if (s.empty() && ans) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
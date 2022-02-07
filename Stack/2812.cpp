#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
stack<int> ans;

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    for (int i=0; i<n; i++) {
        while (!s.empty() && (s.top() < str[i]-'0') && (k > 0)) {
            s.pop();
            k--;
        }
        s.push(str[i] - '0');
    }
    while (!s.empty()){
        if (k-- > 0) {
            s.pop();
            continue;
        }
        ans.push(s.top());
        s.pop();
    }
    while(!ans.empty()) {
        cout << ans.top();
        ans.pop();
    }
    cout << '\n';
    return 0;
}
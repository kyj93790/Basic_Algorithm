#include <iostream>
#include <stack>
using namespace std;

typedef long long ll;
typedef struct node {
    int type;
    ll val;
} node;

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    stack<node> s;
    string str;
    cin >> str;
    for (int i=0; i<str.length(); i++) {
        node temp;
        if (str[i] == '(' || str[i] == '[') {
            temp.type = 0;
            temp.val = str[i];
            s.push(temp);
        }
        else {
            if (str[i] == ')') {
                ll sum = 0;
                while (!s.empty() && s.top().type != 0) {
                    sum += s.top().val;
                    s.pop();
                }
                if (s.empty() || s.top().val != '(') {
                    cout << 0 << '\n';
                    return 0;
                }
                s.pop();
                if (sum == 0) sum++;
                temp.type = 1;
                temp.val = sum * 2;
                s.push(temp);
            } else {
                ll sum = 0;
                while (!s.empty() && s.top().type != 0) {
                    sum += s.top().val;
                    s.pop();
                }
                if (s.empty() || s.top().val != '[') {
                    cout << 0 << '\n';
                    return 0;
                }
                s.pop();
                if (sum == 0) sum++;
                temp.type = 1;
                temp.val = sum * 3;
                s.push(temp);
            }
        }
    }
    ll sum = 0;
    while (!s.empty()) {
        if (s.top().type == 0) {
            cout << 0 << '\n';
            return 0;
        }
        sum += s.top().val;
        s.pop();
    }
    cout << sum << '\n';
    return 0;
}
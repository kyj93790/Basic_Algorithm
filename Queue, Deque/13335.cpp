#include <iostream>
#include <queue>
#include <deque>
using namespace std;

typedef long long ll;
queue<int> bridge;
queue<int> car;

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, w, l, x;
    cin >> n >> w >> l;
    for (int i=0; i<n; i++) {
        cin >> x;
        car.push(x);
    }
    ll ans = 0;
    for (int i=0; i<w; i++) bridge.push(0);
    ll sum = 0; // 현재 bridge 위 하중의 총합
    // 우선 car를 다 bridge로 넘김
    while (!car.empty()) {
        // 일단 한 turn에 bridge 최전방 하나 빠져나옴
        sum -= bridge.front();
        bridge.pop();
        if (sum + car.front() <= l) {
            bridge.push(car.front());
            sum += car.front();
            car.pop();
        } else bridge.push(0);
        ans++;
    }
    // bridge 위에 car가 없을 때까지 빼줌
    while (sum) {
        sum -= bridge.front();
        bridge.pop();
        ans++;
    }
    cout << ans << '\n';
    return 0;
}
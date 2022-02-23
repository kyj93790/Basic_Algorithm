#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll n, k, a, b, x, y, l, t, dir, cx, cy, nx, ny;
char c;

deque<pair<ll, ll> > snake;
queue<pair<ll, char> > rot;
bool visit[111][111];
bool apple[111][111];
int dc[4] = {1, 0, -1, 0};
int dr[4] = {0, 1, 0, -1};

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> k;
    for (int i=0; i<k; i++) {
        cin >> x >> y;
        apple[x][y] = true;
    }
    cin >> l;
    for (int i=0; i<l; i++) {
        cin >> x >> c;
        rot.push(p(x, c));
    }
    snake.push_back(p(1,1));
    visit[1][1] = true;
    dir = 0;
    pair<ll, ll> curr, nxt, tail;
    t = 1;
    while (1) {
        // 다음 index로 방향에 맞게 접근 -> snake 추가
        curr = snake.back(); cx = curr.first; cy = curr.second;
        nx = cx + dr[dir]; ny = cy + dc[dir];

        // 해당 위치의 boundary, visit 여부 판별
        // 경계를 넘어서거나 이미 방문 여부가 있다면 게임 끝 !
        if (nx == 0 || nx > n || ny == 0 || ny > n) break;
        if (visit[nx][ny]) break;
        snake.push_back(p(nx,ny));
        visit[nx][ny] = true;

        // 해당 위치에 사과 없으면 꼬리 줄임
        if (!apple[nx][ny]) {
            tail = snake.front();
            visit[tail.first][tail.second] = false;
            snake.pop_front();
        } else apple[nx][ny] = false;
        // 방향 바꾸는지를 체크
        if (!rot.empty() && rot.front().first == t) {
            if (rot.front().second == 'L') {
                dir = (dir-1 + 4)%4;
            } else {
                dir = (dir+1)%4;
            }
            rot.pop();
        }
        // 시간 증가
        t++;
    }
    cout << t << '\n';
    return 0;
}
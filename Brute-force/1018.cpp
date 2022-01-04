#include <iostream>
using namespace std;

int min_count(char board[50][50], int r, int c) {
    int bc = 0;
    int wc = 0;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if ((r + c + i + j) % 2 == 0) {
                if (board[r + i][c + j] == 'B') wc++;
                else bc++;
            }
            else {
                if (board[r + i][c + j] == 'B') bc++;
                else wc++; 
            }
        }
    }
    if (bc < wc) return (bc);
    else return (wc);
}

int main(void){
    int n, m;
    cin >> n >> m;
    int min = 2500;
    char board[50][50];

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin>>board[i][j];
        }
    }

    for (int i=0; i<=n-8; i++) {
        for (int j=0; j<=m-8; j++) {
            int temp = min_count(board, i, j);
            if (min > temp)
                min = temp;
        }
    }
    cout << min << '\n';
    return (0);
}
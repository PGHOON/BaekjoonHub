#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1000;

int dir_x[4] = {1, 0, -1, 0};
int dir_y[4] = {0, 1, 0, -1};
int M, N;
int day = 0;
int basket[MAX][MAX];
queue<pair<int, int>> q;

void bfs() {
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int j = 0; j < 4; j++) {
                int adj_x = x + dir_x[j];
                int adj_y = y + dir_y[j];
                if (adj_x >= 0 && adj_y >= 0 && adj_x < N && adj_y < M && basket[adj_x][adj_y] == 0) {
                    basket[adj_x][adj_y] = day + 1;
                    q.push({adj_x, adj_y});
                }
            }
        }
        day++;
    }
}

int main() {
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> basket[i][j];
            if (basket[i][j] == 1)
                q.push({i, j});
        }
    }
    bfs();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (basket[i][j] == 0) {
                cout << "-1" << endl;
                return 0;
            }
        }
    }
    cout << day - 1 << endl;
    return 0;
}

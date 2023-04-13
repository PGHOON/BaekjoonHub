#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int MAX = 100;

int dir_x[6] = {1, 0, -1, 0, 0, 0};
int dir_y[6] = {0, 1, 0, -1, 0, 0};
int dir_z[6] = {0, 0, 0, 0, 1, -1};
int M, N, H;
int day = 0;
int basket[MAX][MAX][MAX];
queue<tuple<int, int, int>> q;

void bfs() {
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            int x = get<0>(q.front());
            int y = get<1>(q.front());
            int z = get<2>(q.front());
            q.pop();
            for (int j = 0; j < 6; j++) {
                int adj_x = x + dir_x[j];
                int adj_y = y + dir_y[j];
                int adj_z = z + dir_z[j];
                if (adj_x >= 0 && adj_y >= 0 && adj_z >= 0 && adj_x < N && adj_y < M && adj_z < H && basket[adj_x][adj_y][adj_z] == 0) {
                    basket[adj_x][adj_y][adj_z] = day + 1;
                    q.push({adj_x, adj_y, adj_z});
                }
            }
        }
        day++;
    }
}

int main() {
    cin >> M >> N >> H;
    for(int h = 0; h < H; h++){
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> basket[i][j][h];
                if (basket[i][j][h] == 1)
                    q.push({i, j, h});
            }
        }
    }
    bfs();
    for (int h = 0; h < H; h++){
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (basket[i][j][h] == 0) {
                    cout << "-1" << endl;
                    return 0;
                }
            }
        }
    }
    cout << day - 1 << endl;
    return 0;
}
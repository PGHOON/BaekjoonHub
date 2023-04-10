#include <iostream>
#include <queue>
#define MAX 101

using namespace std;

int N, M;
int MAZE[MAX][MAX];
int visited[MAX][MAX];
int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

namespace Search {
    int distance[MAX][MAX] = {0, };

    void bfs(int x, int y){
        queue<pair<int, int>> q;
        visited[x][y] = 1;
        Search::distance[x][y] = 1;
        q.push(make_pair(x, y));
        while(!q.empty()){
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int x_adjacent = x + dir_x[i];
                int y_adjacent = y + dir_y[i];
                if((1 <= x_adjacent && x_adjacent <= N) && (1 <= y_adjacent && y_adjacent <= M)
                  && (!visited[x_adjacent][y_adjacent]) && (MAZE[x_adjacent][y_adjacent] == 1)){
                    visited[x_adjacent][y_adjacent] = 1;
                    Search::distance[x_adjacent][y_adjacent] = Search::distance[x][y] + 1;
                    q.push(make_pair(x_adjacent, y_adjacent));
                }
            }
        }
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            scanf("%1d", &MAZE[i][j]);
        }
    }
    Search::bfs(1,1);
    printf("%d", Search::distance[N][M]);
    return 0;
}

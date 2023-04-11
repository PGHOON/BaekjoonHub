#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 300

typedef struct {
    int x;
    int y;
} Point;

int board[MAX_SIZE][MAX_SIZE];
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

void bfs(Point start, Point end, int l) {
    memset(board, -1, sizeof(board));
    board[start.x][start.y] = 0;
    Point queue[MAX_SIZE * MAX_SIZE];
    int front = 0;
    int rear = 0;
    queue[rear++] = start;
    while (front != rear) {
        Point curr = queue[front++];
        for (int i = 0; i < 8; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];
            if (nx >= 0 && nx < l && ny >= 0 && ny < l && board[nx][ny] == -1) {
                board[nx][ny] = board[curr.x][curr.y] + 1;
                queue[rear++] = (Point) {nx, ny};
                if (nx == end.x && ny == end.y) {
                    return;
                }
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int l;
        scanf("%d", &l);
        Point start, end;
        scanf("%d%d%d%d", &start.x, &start.y, &end.x, &end.y);
        bfs(start, end, l);
        printf("%d\n", board[end.x][end.y]);
    }
    return 0;
}
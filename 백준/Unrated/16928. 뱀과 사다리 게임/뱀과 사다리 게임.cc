#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

int N, M, x, y;
int MAP[MAX] = {0,};
int visited[MAX] = {0,};
queue<int> q;

void bfs(){
    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(int dice = 1; dice <= 6; dice++){
            int next = current + dice;
            if(next == 100){
                printf("%d", visited[current]);
                return;
            } else if(next < 100){
                while(MAP[next] != 0) {
                    next = MAP[next];
                }
                if(visited[next] == 0){
                    visited[next] = visited[current] + 1;
                    q.push(next);
                }
            }
        }
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N+M; i++){
        scanf("%d %d", &x, &y);
        MAP[x] = y;
    }
    q.push(1);
    visited[1] = 1;
    bfs();
    return 0;
}

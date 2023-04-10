#include <iostream>
#include <queue>
#define MAX 1000001

using namespace std;

int N, K;
int visited[MAX];

void bfs(int v){
    visited[v] = 1;
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        v = q.front();
        q.pop();
        if(v == K){
            printf("%d", visited[v]-1);
            break;
        } if(v - 1 >= 0 && visited[v-1] == 0){
            q.push(v-1);
            visited[v-1] = visited[v] + 1;
        } if(v + 1 < MAX && visited[v+1] == 0){
            q.push(v+1);
            visited[v+1] = visited[v] + 1;
        } if(v*2 < MAX && visited[2*v] == 0){
            q.push(2*v);
            visited[2*v] = visited[v] + 1;
        }
    }
}

int main(){
    scanf("%d %d", &N, &K);
    bfs(N);
    
    return 0;
}
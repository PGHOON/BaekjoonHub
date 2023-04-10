#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001

int adjacent[MAX][MAX];
bool visited[MAX] = {false, };
int N, M, V;

void dfs(int v){
    visited[v] = true;
    cout << v << " ";
    for(int i = 1; i <= N; i++){
        if(visited[i] == true || adjacent[v][i] == 0)
            continue;
        dfs(i);
    }
}

void bfs(int v){
    queue<int> q;
    visited[v] = false;    //문제에서 DFS를 먼저 돌기 때문에 1이 default.
    q.push(v);
    while(!q.empty()){
        v = q.front();
        cout << v << " ";
        q.pop();
        for(int i = 1; i <= N; i++){
            if(visited[i] == false || adjacent[v][i] == 0)
                continue;
            q.push(i);
            visited[i] = false;
        }
    }
    
}

int main(){
    int x, y;
    cin >> N >> M >> V;
    for(int i = 0; i < M; i++){
        cin >> x >> y;
        adjacent[x][y] = 1;
        adjacent[y][x] = 1;
    }
    dfs(V);
    cout << endl;
    bfs(V);
    return 0;
}
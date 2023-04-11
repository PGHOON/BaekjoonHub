#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100001
using namespace std;

vector<int> MAP[MAX];
int visited[MAX] = {0,};
int order[MAX] = {0,};
int N, M, R, u, v;
int cnt = 0;

void dfs(int r){
    if(visited[r]==1)
        return;
    visited[r] = 1;
    cnt++;
    order[r] = cnt;
    for(int i = 0; i<MAP[r].size(); i++){
        int x = MAP[r][i];
        dfs(x);
    }
}

int main(){
    scanf("%d %d %d", &N, &M, &R);
    for(int i = 1; i <= M; i++){
        scanf("%d %d", &u, &v);
        MAP[u].push_back(v);
		MAP[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) {
		sort(MAP[i].begin(), MAP[i].end());
	}
    dfs(R);
    for(int i = 1; i <= N; i++)
        printf("%d\n", order[i]);
}
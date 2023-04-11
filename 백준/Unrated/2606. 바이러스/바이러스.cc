#include <iostream>
#define MAX 101
#define INFECTEE 1
using namespace std;

int NUM_PC, NUM_Conn, pc1, pc2, infection = -1;
int MAP[MAX][MAX] = {0, };
int visited[MAX] = {0, };

void dfs(int virus){
    infection++;
    visited[virus] = 1;
    for(int i = 1; i <= NUM_PC; i++){
        if(visited[i] == 1 || MAP[virus][i] == 0)
            continue;
        dfs(i);
    }
}

int main(){
    scanf("%d %d", &NUM_PC, &NUM_Conn);
    for(int i = 0; i < NUM_Conn; i++){
        scanf("%d %d", &pc1, &pc2);
        MAP[pc1][pc2] = MAP[pc2][pc1] = 1;
    }
    dfs(INFECTEE);
    printf("%d", infection);
}
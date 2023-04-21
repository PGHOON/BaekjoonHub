#include <stdio.h>

int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    
    int N[n][m];
    int M[n][m];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &N[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &M[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", M[i][j] + N[i][j]);
        }
        printf("\n");
    }
    return 0;
}
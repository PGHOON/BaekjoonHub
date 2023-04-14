#include <stdio.h>

int main(){
    int N, K, MIN=0;
    int coin[11];
    scanf("%d %d", &N, &K);
    for(int i = 1; i <= N; i++){
        scanf("%d", &coin[i]);
    }
    for(int i = N; i >= 0; i--){
        MIN += K / coin[i];
        K = K % coin[i];
    }
    printf("%d", MIN);
}
#include <stdio.h>

int main(){
    int k, q, r, b, n, p;
    int K = 1, Q = 1, R = 2, B = 2, N = 2, P = 8;
    scanf("%d %d %d %d %d %d", &k, &q, &r, &b, &n, &p);
    printf("%d %d %d %d %d %d", K-k, Q-q, R-r, B-b, N-n, P-p);
    return 0;
}
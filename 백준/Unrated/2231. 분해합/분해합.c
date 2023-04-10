#include <stdio.h>

int main(){
    int N, digit = 0;
    scanf("%d", &N);
    int M = N;
    int flag = 0;
    while(M){
        M /= 10;
        digit++;
    }
    int start = N - 9 * digit;
    for(int i = start; i <=  N; ++i){
        int temp = i;
        int sum = i;
        while(temp){
            sum += temp % 10;
            temp /= 10;
        }
        if (sum == N){
            printf("%d", i);
            flag=1;
            break;
        }
    }
    if(flag==0)
        printf("0");
    return 0;
}
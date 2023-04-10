#include <stdio.h>

int main(){
    int N, M;
    int arr[100];
    scanf("%d %d", &N, &M);
    int MaximumSum = 0, CurrentSum = 0, TargetSum = M;
    
    for(int i = 0; i < N; i ++){
        scanf("%d", &arr[i]);
    }
    
    for(int i = 0; i < N; i ++){
        for(int j = i+1; j < N; j++)
            for(int k = j+1; k < N; k++){
                CurrentSum = arr[i] + arr[j] + arr[k];
                if(CurrentSum > MaximumSum && CurrentSum <= TargetSum)
                    MaximumSum = CurrentSum;
            }
    }
    printf("%d", MaximumSum);
    return 0;
}
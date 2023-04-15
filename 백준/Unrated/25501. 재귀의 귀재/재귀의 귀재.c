#include <stdio.h>
#include <string.h>

int count;

int recursion(const char *s, int l, int r){
    count++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    count = 0;
    return recursion(s, 0, strlen(s)-1);
}

int main(){
    int T;
    char S[1001];
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        scanf("%s", S);
        printf("%d ", isPalindrome(S));
        printf("%d\n", count);
    }
    return 0;
}
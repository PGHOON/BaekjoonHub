#include <stdio.h>
#include <string.h>

//a~z in ascii are 97~122

int main(){
    int alphabet[26];
    char S[100];
    scanf("%s", S);
    
    for(int i = 0; i < 26; i++){
    alphabet[i] = -1;
    }
    
    for(int i = 97; i <= 122; i++){
        for(int j = 0; j < strlen(S); j++){
            if(S[j] == i){
                alphabet[S[j] - 'a'] = j;
                break;
            }
        }
    }
    for(int i = 0; i < 26; i++){
        printf("%d ", alphabet[i]);
    }
    return 0;
}
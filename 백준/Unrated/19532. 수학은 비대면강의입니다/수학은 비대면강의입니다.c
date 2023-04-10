#include <stdio.h>

int main(){
    int a, b, c, d, e, f;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    
    int x = (c * e - b * f) / (a * e - b * d);
    int y = (c * d - a * f) / (b * d - a * e);
    
    printf("%d %d", x, y);
    return 0;
}
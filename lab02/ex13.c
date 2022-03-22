#include <stdio.h>

int main(void){
    int n,m;
    scanf("%d %d", &n, &m);
    if (n%m == 0){
        printf("yes\n");
        return 0;
    }
    else{
        printf("no\n");
        return 0;
    }
    return 0;
}
#include <stdio.h>

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    if (n > m){
        printf("%d\n",m);
        printf("%d\n",n);
    }
    else{
        printf("%d\n",n);
        printf("%d\n",m);
    }
    return 0;
}
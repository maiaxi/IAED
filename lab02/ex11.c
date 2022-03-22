#include <stdio.h>

int main(void){
    int n = 0, i = 0, sum = 0, act = 0;
    scanf("%d", &n);
    while (n/10 >= 1 || n == 1){
        act = n%10;
        sum += act;
        n = n/10;
        i++;
    }
    printf("%d\n", i);
    printf("%d\n", sum);
    return 0;
}
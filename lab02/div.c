#include<stdio.h>

int main(void){
    int d = 0;
    int n = 0;
    scanf("%d", &n);
    if(n>0){
        int i;
        i = 2;
        while (i <= n/2){
            if (n % i == 0){
                printf("%i é divisível por %i, ", n, i);
                d++;}
            i++;
        }
        if(d == 0){
            printf("%i é primo.", n);
        }
    }
    return 0;
}
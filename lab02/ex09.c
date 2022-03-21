#include <stdio.h>

int main(void) {
    int total = 0, i = 0;
    float sum = 0, act = 0, avg = 0;
    scanf("%d", &total);
    for (i; i < total; i++){
        scanf("%f", &act);
        sum += act;
    }
    avg = sum/total;
    printf("%f", avg);
    return 0;
}
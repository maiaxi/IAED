#include <stdio.h>

int main(void){
    int sec = 0, hrs = 0, min = 0;
    scanf("%d", &sec);
    hrs = sec/3600;
    sec = sec - 3600 * hrs;
    min = sec / 60;
    sec = sec - 60 * min;
    if (hrs<10 && min<10 && sec<10){
        printf("0%d:0%d:0%d\n", hrs , min, sec);
    }
    else if (hrs<10 && min>10 && sec<10){
        printf("0%d:%d:0%d\n", hrs , min, sec);
    }
    else if (hrs<10 && min<10 && sec>10){
        printf("0%d:0%d:%d\n", hrs , min, sec);
    }
    else if (hrs<10 && min>10 && sec>10){
        printf("0%d:%d:%d\n", hrs , min, sec);
    }
        if (hrs>10 && min<10 && sec<10){
        printf("%d:0%d:0%d\n", hrs , min, sec);
    }
    else if (hrs>10 && min>10 && sec<10){
        printf("%d:%d:0%d\n", hrs , min, sec);
    }
    else if (hrs>10 && min<10 && sec>10){
        printf("%d:0%d:%d\n", hrs , min, sec);
    }
    else if (hrs>10 && min>10 && sec>10){
        printf("%d:0%d:0%d\n", hrs , min, sec);
    }
    return 0;
}
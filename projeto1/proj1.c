#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int main(void){
    char command[50];
    int res;
    int i;
    scanf("%s", command);
        for (i=0; i<1; i++){
            res = command[i];
        }
    printf("%c \n", res);
    if(res == 'q'){
        printf("Acabou");
        exit(0);
    }
    else if(res == a){
        printf("vais fazer outra coisa");
    }
    return 0;
}

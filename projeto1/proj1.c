#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define DIM 88


/*struct airport {
    char ID[3];
    char country[30];
    char city[50];
    int incflights;
    int outflights;
}*/
void newapt(char command){
    int apt[DIM];
    int i = 2;
    for (i; i<DIM; i++){
        apt += command[i];
    }
    printf("%ls", apt);
 }

int main(void){
    char command[DIM];
    char apt[DIM];
    int res;
    int i;
    fgets(command, DIM, stdin);
    res = command[0];
    switch(res){
        case('q'):
            return 0;
        case('a'):
            apt = newapt(command);
            return 0;
    }
}

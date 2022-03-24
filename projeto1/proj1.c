#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int main(void){
    char command[88];
    int res;
    int i;
    scanf("%s", command);
    res = command[0];
    switch(res){
        case('q'):
            return 0;
        case('a'):
            printf("a");
    }
}

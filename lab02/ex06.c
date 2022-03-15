#include<stdio.h>

int main(void){
    int a=0,b=0,c=0;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    if(b > a){
        if(b > c){
            printf("%d", b);
        }
        else{
            printf("%d",c);
        }
    }    
    else{
        if(a>c){
            printf("%d", a);
        }
        else{
            printf("%d", c);
        }
    }
    return 0;
}
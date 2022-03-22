#include <stdio.h>

int main(void){
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    if (a<b){
        if (b<c){
            printf("%d %d %d\n",a,b,c);
        }
        else if (a<c){
            printf("%d %d %d\n",a,c,b);
        }
    }
    if (b<a){
        if (a<c){
            printf("%d %d %d\n",b,a,c);
        }
        else if(b<c){
            printf("%d %d %d\n",b,c,a);
        }
    }
    if (c<a){
        if (a<b){
            printf("%d %d %d\n",c,a,b);
        }
        else if(c < b){
            printf("%d %d %d\n",c,b,a);
        }
    }
    return 0;
}
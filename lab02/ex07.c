#include<stdio.h>

int main(void){
    float max,min,atual=0;
    int total=0;
    scanf("%d", &total);
    int i=0;
    while(i<total){
        if(i==0){
            scanf("%f", &atual);
            max = atual;
            min = atual;
            i++;
        }
        else{
            i++;
            scanf("%f", &atual);
            if(atual > max)
                max = atual;
            
            else if(atual < min)
                min = atual;
        }
    }
    printf("min: %f, max: %f\n", min, max);
    return 0;
}
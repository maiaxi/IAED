#include<math.h>
#include<stdio.h>
#define DIM 100
double trapz(double x[DIM], double y[DIM],int n){
    int i = 0;
    double total = 0, act;
    for (i = 0; i +1 < n; i++){
        act = (x[i+1]-x[i])*((y[i]+y[i+1])/2);
        printf("act :%lf\n", act);
        total = total + act;
    }
    return total;
}


int main(void){
    int n = 0, i;
    double x[DIM], y[DIM];
    for (i = 0; i < DIM; i++){
        scanf("%lf", &x[i]);
        scanf("%lf", &y[i]);
        n++;
    }
    printf("%lf", trapz(x, y, n));
    return 0;
}
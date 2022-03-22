#include <stdio.h>
#include <stdlib.h>

void piramide(int n){
    int col = 1, lin = 1, dist = n - 1, len = n * 2 - 1;
    while (lin <= n){
        if (col == len && lin != n){
            printf("  ");
            printf("\n");
            lin++;
            col = 1;
            dist = n - 1;
        }
        else if (col == len && lin == n){
            printf("1\n");
            break;
        }
        else if (abs(dist) < lin){
            int e = 0;
            printf("%d ", lin-abs(dist));
            dist --;
            col++;
            e++;
        }
        else{
            printf("  ");
            dist--;
            col++;
        }
    }
}


int main(void){
    int n;
    scanf("%d", &n);
    piramide(n);
    return 0;
}


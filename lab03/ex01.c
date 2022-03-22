#include<stdio.h>


void quadrado(int n);

int main(void){
    int n;
    scanf("%d", &n);
    quadrado(n);
    return 0;
}
void quadrado(int n){
    int colunas = 0 , linhas = 1;
    while (colunas < n+linhas -1){
        printf("%d\t", ++colunas);
    
        if (colunas == n+linhas -1){
            colunas = linhas;
            printf("\n");
            linhas++;
        }
        if (linhas == n +1){
            break;
        }
    }
}

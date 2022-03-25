#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define DIM 88
#define AIRPORTS_MAX 40

typedef struct airport{
            char ID[3];
            char country[30];
            char city[50];
            int incflights;
            int outflights;
} airport;

airport list_airports[AIRPORTS_MAX];

void newapt(char command){
	int i = 2, actual;
	actual = command[i];
	for(i; actual != ' '; i++){
		printf("%c", command[i]);
	}
}

int main(void){
    char command[DIM];
    int i, res;
    scanf("%[^\n]%*c", command);
    switch(command[0]){
        case('q'):
            exit(0);
        case('a'):
            newapt(command);
    }
}
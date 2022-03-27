#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define DIM 88
#define AIRPORTS_MAX 40

struct airport{
    char id[3];
    char country[30];
    char city[50];
    int incflights;
    int outflights;
};

struct airport list_airports[AIRPORTS_MAX];

int main(void);

char* getid(char *command,char *id){
    int i = 2, e = 0;
    int idsize;
    while (i < 5 ){
        id[e] = command[i];
        e++;
        i++;
    }
    idsize = strlen(id);
    if (idsize != 3){
        printf("invalid airport ID");
        main();
    }
    for (i=0; i<idsize; i++){
        if (id[i]<65 || id[i] > 90){
            printf("invalid airport ID");
            main();
        }
    }
    return id;
}

void getcountry(char* command, char* country){
    int i = 6, e = 0;
    while (command[i]!= ' '){
        country[e] = command[i];
        e++;
        i++;
    }
}

void getcity(char* command, char* city){
    int i = 6, e = 0;
    int size;
    size = strlen(command);
    while (command[i]!= ' '){
        e++;
        i++;
    }
    if(i+2 != size){
        i++;
        e = 0;
    }
    while (i < size){
        city[e] = command [i];
        i++;
        e++;
    }
}


void newapt(char * command){
    struct airport apt;
    char id[3];
    char country[30];
    char city[50];
    getid(command, id);
    getcountry(command, country);
    getcity(command, city);
    strcpy(apt.id , id);
    printf("airport %s", apt.id);
}

int main(void){
    char command[DIM];
    scanf("%[^\n]%*c", command);
    switch (command[0]){
        case ('q'):
            exit(0);
        case ('a'):
            newapt(command);
    }
    return 0;
}
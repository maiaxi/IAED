#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define DIM 88
#define AIRPORTS_MAX 40

typedef struct airport {
    char id[4];
    char country[30];
    char city[50];
    int incflights;
    int outflights;
}airport;

struct airport list_airports[AIRPORTS_MAX];

int main(void);

char* getid(char *command,char *id){
    char com1[88];
    int i = 2, e = 0;
    int idsize;
    strcpy(com1, command);
    while (i < 5 ){
        id[e] = com1[i];
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

char* getcountry(char* command, char* country){
    int i = 6, e = 0;
    char com2[88];
    strcpy(com2, command);
    while (com2[i]!= ' '){
        country[e] = com2[i];
        e++;
        i++;
    }
    return country;
}

char* getcity(char* command, char* city){
    int i = 6, e = 0;
    int size;
    char com3[88] ;
    strcpy(com3,command);
    size = strlen(com3);
    while (com3[i]!= ' '){
        e++;
        i++;
    }
    if(i+2 != size){
        i++;
        e = 0;
    }
    while (i < size){
        city[e] = com3[i];
        i++;
        e++;
    }
    return city;
}


void newapt(char * command){
    airport apt;
    char id[4];
    char country[30];
    char city[50];
    /*int i = 0, equal;*/
    getid(command,id);
    getcountry(command, country);
    getcity(command, city);
    strcpy(apt.id, id);
    strcpy(apt.country, country);
    strcpy(apt.city, city);
    apt.incflights = 0;
    apt.outflights = 0;
    /*for (i = 0 ; i <= AIRPORTS_MAX; i++){
        equal = strcmp(list_airports[i].id,apt.id);
        if(list_airports[i].buf != NULL){
            if(equal == 0){
                printf("duplicate airport");
                main();
            }
        }       
        else if(list_airports[i].buf == NULL){
            list_airports[i] = apt; 
        }
    }*/
    printf("airport: %s ", apt.id);
    main();
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
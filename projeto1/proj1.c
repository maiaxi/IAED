#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define DIM 88
#define AIRPORTS_MAX 40

typedef struct airport {
    char id[4];
    char country[31];
    char city[51];
    int incflights;
    int outflights;
}Airport;

Airport list_airports[AIRPORTS_MAX];

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
    }
    for (i=0; i<idsize; i++){
        if (id[i]<65 || id[i] > 90){
            printf("invalid airport ID");
        }
    }
    return id;
}

char* getcountry(char* command, char* country){
    int i = 6, e = 0;
    char com2[88];
    strcpy(com2, command);
    while (com2[i]!= ' ' && com2[i]!= '\t'){
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


Airport newApt(char * command){
    Airport apt;
    char id[4];
    char country[30];
    char city[50];
    getid(command,id);
    getcountry(command, country);
    getcity(command, city);
    strcpy(apt.id, id);
    strcpy(apt.country, country);
    strcpy(apt.city, city);
    apt.incflights = 0;
    apt.outflights = 0;
    
    return apt;
}

void addApt(Airport apt){
    int i = 0 , equal,empty;
    char *idd = list_airports[i].id;
    for (i = 0 ; i <= AIRPORTS_MAX; i++){
        empty = strcmp(idd, "\000"),
        equal = strcmp(list_airports[i].id, apt.id);
        if (empty != 0){
            if (equal == 0){
                printf("duplicate airport");
                break;
            }
        }
        else if (empty == 0){
            list_airports[i] = apt;
            printf("airport %s", list_airports[i].id);
            break;
        }
        else if (i = AIRPORTS_MAX){
            printf("too many airports");
            break;
        }
    }
}

void listApt(command);


int main(void){
    char command[DIM];
    while (command[0]!= 'q'){
        scanf("%[^\n]%*c", command);
        switch (command[0]){
            case ('a'):
                addApt(newApt(command));
            case ('l'):
                listApt(command);
        }
    }
    return 0;
}
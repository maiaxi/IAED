#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define DIM 161
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
        return "\000";
    }
    for (i=0; i<idsize; i++){
        if (id[i]<65 || id[i] > 90){
            printf("invalid airport ID");
            return "\000";
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
    char *idd;
    for (i = 0 ; i <= AIRPORTS_MAX; i++){
        idd = list_airports[i].id;
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
        else if (i == AIRPORTS_MAX){
            printf("too many airports");
            break;
        }
    }
}

void listApt(char *command){
    if (strlen(command) == 1){
        int i = 0, e = 0, empty,size = 0;
        char *idd = list_airports[e].id;
        empty = strcmp(idd, "\000");
        for(e = 0; empty != 0 ; e++){
            idd = list_airports[e].id;
            empty = strcmp(idd, "\000");
            if (empty == 0){
                break;
            }
            size++;
        }
        for(i = 0; i < size; i++){
            printf("id: %s \n",list_airports[i].id);
        }
    }
    else{
        char ids[40];
        char id[4];
        char *pids[40];
        int i = 0, e = 0,f = 0;
        int size = strlen(command);
        for(i = 2; i < size; i++){
            if(command[i] != ' ' || command[i] != '\t' || command[i] != '\0'){
                id[e] = command[i];
                e++;
            }
            else if (command[i] == ' ' || command[i + 1] == '\t'){
                strcpy(pids[f], id);
                e = 0;
                f++;
            }
            else{
                break;
            }
        }
        printf("%s", ids);
    }
}

void

int main(void){
    char command[DIM];
    while (command[0]!= 'q'){
        scanf("%[^\n]%*c", command);
        switch (command[0]){
            case 'a':
                addApt(newApt(command));
                break;
            case 'v':
                newFlight(command);
            case 'l':
                listApt(command);
                break;
        }
    }
    return 0;
}
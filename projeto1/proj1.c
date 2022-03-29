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

int dupId(char *id){
    int i, equal;
    for (i = 0; i < AIRPORTS_MAX; i++){
        equal = strcmp(id, list_airports[i].id);
        if (equal == 0){
            printf("duplicate airport");
            return 1;
        }
    }
    return 0;
}


int validId(char *id){
    int i;
    if (strcmp(list_airports[39].id,"\000") != 0){
        printf("too many airports");
        return 0;
    }
    for (i = 0; i < 3; i++){
        if (id[i] < 'A' || id[i] > 'Z'){
            printf("invalid airport id");
            return 0;
        }
    }
    if (dupId(id) == 1){
        return 0;
    }
    return 1; 
}

char* getid(char *command, char *id){
    char com1[DIM];
    int i = 2, e = 0;
    strcpy(com1, command);
    while (i <= 4 ){
        id[e] = com1[i];
        e++;
        i++;
    }
    return id;
}


char* getcountry(char* command, char* country){
    int i = 6, e = 0;
    char com2[DIM];
    strcpy(com2, command);
    while (com2[i]!= ' ' && com2[i]!= '\t'){
        country[e++] = com2[i++];
    }
    country[e]='\0';
    return country;
}


char* getcity(char* command, char* city){
    int i = 6, e = 0;
    int size;
    char com3[DIM] ;
    strcpy(com3,command);
    size = strlen(com3);
    for (i = 6; com3[i]!= ' ' && com3[i]!= '\t'; i++){
    }
    for (i++; i <= size; i++){
        city[e] = com3[i];
        e++;
    }
    return city;
}


void newApt(char * command){
    Airport apt;
    char id[4];
    char country[31];
    char city[51];
    int i = 0 , empty;
    getid(command,id);
    getcountry(command, country);
    getcity(command, city);
    strcpy(apt.id, id);
    strcpy(apt.country, country);
    strcpy(apt.city, city);
    apt.incflights = 0;
    apt.outflights = 0;
    if (validId(apt.id) == 1 ){
        for (i = 0 ; i <= AIRPORTS_MAX; i++){
            empty = strcmp(list_airports[i].id, "\0");
            if (empty == 0){
                list_airports[i] = apt;
                printf("airport %s\n", list_airports[i].id);
                break;
            }
        }
    }
}


void sort(char list[40][4], int size){
    int i = 0, compare = 0, minors = 0;
    char temp[4];
    for (i = 0; i < size; i++){
        compare = strcmp(list[i], list[i+1]);   /*if >0 , list[i]>list[i+1] */
        if (minors == size-1){
            break;
        }
        if(compare > 0){
            minors = 0;
            if(i + 1 == size){
                i=-1;
            }
            else{
                strcpy(temp, list[i]);
                strcpy(list[i], list[i+1]);
                strcpy(list[i+1], temp);    
            }
        }
        if(compare < 0){
            minors++;
            if(i + 1 == size){
                i=-1;
            }   
        }   
    }   
}


void specific_list(char *com){
    char idsarray[AIRPORTS_MAX][4];
    int i = 2, e = 0, y = 0, len;
    len = strlen(com);
    for (i = 2; i < len; i ++){
        if(com[i] == ' ' || com[i] == '\t'){
            idsarray[y][4] = '\0';
            i++;
            e = 0;
            y++;
        }
        else{
            idsarray[y][e] = com[i];
            e++;
        }
    }
    len = strlen(idsarray[AIRPORTS_MAX]);
    for (i = 0; i < len a ; i++){
        printf("%s", idsarray[i]);
    }
}

void emptyl(void){
    int i = 0, e = 0, empty, size = 0, y = 0,z = 0, equalid = 0;
    char idlist[40][4];
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
    for (i = 0; i<size; i++){
        strcpy (idlist[i], list_airports[i].id);    
    }
    sort(idlist, size);
    while( y < size){
        equalid = strcmp(idlist[y],list_airports[z].id);
        if (equalid == 0){
            printf("%s %s %s %d \n", list_airports[z].id, list_airports[z].city, list_airports[z].country, list_airports[z].outflights);
            y++;
            z = 0;
        }
        else if (equalid != 0){
            z++;
        }
    }   
}      


void listApt(char *command){
    if (strlen(command) == 1){
        emptyl();
    }
    else{
        specific_list(command);
    }
}
        


int main(void){
    char command[DIM];
    while (command[0]!= 'q'){
        scanf("%[^\n]%*c", command);
        fflush(stdin);
        switch (command[0]){
            case 'a':
                newApt(command);
                break;
            case 'l':
                listApt(command);
                break;
        }
    }
    return 0;
}

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
    char com1[DIM];
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
    char com2[DIM];
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
    char com3[DIM] ;
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
    char country[31];
    char city[51];
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
}   }   }   }


void listApt(char *command){
    if (strlen(command) == 1){
        int i = 0, e = 0, empty, size = 0, y = 0,z = 0, equalid = 0;
        char idlist[40][4];
        char *idd = list_airports[e].id;
        empty = strcmp(idd, "\000");
        for(e = 0; empty != 0 ; e++){
            idd = list_airports[e].id;
            empty = strcmp(idd, "\000");
            if (empty == 0){
                break;  }
            size++; }
        for (i = 0; i<size; i++){
            strcpy (idlist[i], list_airports[i].id);    
        }
        sort(idlist, size);
        while( y < size){
            equalid = strcmp(idlist[y],list_airports[z].id);
            if (equalid == 0){
                printf("%s %s %s #%d ", list_airports[z].id, list_airports[z].city, list_airports[z].country, list_airports[z].outflights);
                y++;
                z = 0;  }
            else if (equalid != 0){
                z++;
}   }   }   }


int main(void){
    char command[DIM];
    while (command[0]!= 'q'){
        scanf("%[^\n]%*c", command);
        switch (command[0]){
            case 'a':
                addApt(newApt(command));
                break;
            case 'l':
                printf("id: %s city: %s country:%s flights: %d", list_airports[0].id, list_airports[0].city, list_airports[0].country, list_airports[0].outflights);
                listApt(command);
                break;
        }
    }
    return 0;
}


#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define COM_DIM 161
#define ID_SIZE 4
#define COUNTRY_SIZE 31
#define CITY_SIZE 51
#define AIRPORTS_MAX 40
#define LET_SIZE 2
#define FLIGHTS_MAX 30000

typedef struct Date{
    int day;
    int month;
    int year;
}Date;

typedef struct Id{
    char let[LET_SIZE];
    int number;
}Id;

typedef struct Hour{
    int hour;
    int minutes;
}Hour;

Date today;



typedef struct Flight{
    Id id;
    char departure[ID_SIZE];
    char arrival[ID_SIZE];
    Date date;
    Hour hour;
    Hour duration;
    int capacity;
    Hour creation;
}Flight;



typedef struct Airport{
    char id[ID_SIZE];
    char country[COUNTRY_SIZE];
    char city[CITY_SIZE];
    int departures;
}Airport;

Flight flights[FLIGHTS_MAX];

Airport list_airports[AIRPORTS_MAX];

int dupId(char *id){
    int i, equal;
    for (i = 0; i < AIRPORTS_MAX; i++){
        equal = strcmp(id, list_airports[i].id);
        if (equal == 0){
            return 1;
        }
    }
    return 0;
}


int validId(char *id){
    int i;
    if (strcmp(list_airports[39].id,"\000") != 0){
        printf("too many airports\n");
        return 0;
    }
    for (i = 0; i < 3; i++){
        if (id[i] < 'A' || id[i] > 'Z'){
            printf("invalid airport ID\n");
            return 0;
        }
    }
    if (dupId(id) == 1){
        printf("duplicate airport\n");
        return 0;
    }
    return 1; 
}

char* getid(char *command, char *id){
    char com1[COM_DIM];
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
    char com2[COM_DIM];
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
    char com3[COM_DIM] ;
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


void sort(char list[AIRPORTS_MAX][ID_SIZE], int size){
    int i = 0, compare = 0, minors = 0;
    char temp[ID_SIZE];
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

int AptbyId(char *id){
    int i, equal;
    char idd[ID_SIZE];
    strcpy(idd, id);
    for (i = 0; i < AIRPORTS_MAX; i++){
        equal = strcmp(idd, list_airports[i].id);
        if (equal == 0){
            return i;
        }
    }
    return -1;
}

void specific_list(char *com){
    char idsarray[AIRPORTS_MAX][ID_SIZE], actualid[ID_SIZE];
    int i = 2, e = 0, y = 0,z = 0, len, empty;
    for (i = 0; i < AIRPORTS_MAX; i++){
        strcpy(idsarray[i], "\0\0\0");
    }
    len = strlen(com);
    for (i = 2; i <= len; i ++){
        if(i == len){
            actualid[e] = '\0';
            strcpy(idsarray[y], actualid);
        }
        else if(com[i] == ' ' || com[i] == '\t' ){
            actualid[e] = '\0';
            strcpy(idsarray[y], actualid);
            e = 0;
            y++;
        }
        else{
            actualid[e] = com[i];
            e++;
        }
    }
    len = 0;
    for (i = 0; i < AIRPORTS_MAX; i++){
        empty = strcmp(idsarray[i], "\000");
        if (empty == 0){
            break;
        }
        len++;
    }
    for (i = 0; i < len ; i++){
        if (dupId(idsarray[i]) == 1){
            z = AptbyId(idsarray[i]);
            printf("%s %s %s %d\n", list_airports[z].id, list_airports[z].city, list_airports[z].country, list_airports[z].departures);
        }
        else{
            printf("%s: no such airport ID\n", idsarray[i]);
        }
    }
}


void emptyl(void){
    int i = 0, e = 0, empty, size = 0, y = 0,z = 0, equalid = 0;
    char idlist[AIRPORTS_MAX][ID_SIZE];
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
            printf("%s %s %s %d\n", list_airports[z].id, list_airports[z].city, list_airports[z].country, list_airports[z].departures);
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

void newApt(char * command){
    Airport apt;
    char id[ID_SIZE];
    char country[COUNTRY_SIZE];
    char city[CITY_SIZE];
    int i = 0 , empty;
    getid(command,id);
    getcountry(command, country);
    getcity(command, city);
    strcpy(apt.id, id);
    strcpy(apt.country, country);
    strcpy(apt.city, city);
    apt.departures = 0;
    if (validId(apt.id) == 1 ){
        for (i = 0 ; i < AIRPORTS_MAX; i++){
            empty = strcmp(list_airports[i].id, "\0");
            if (empty == 0){
                list_airports[i] = apt;
                printf("airport %s\n", list_airports[i].id);
                break;
            }
        }
    }
}
/*
void newFlight(char command){
    Flight flight;
    ID id;
    char departure[ID_SIZE], char arrival[ID_SIZE];
    Date date;
    Hour hour, duration creation;
    int capacity;
}
        

void flight(char * command){
    if (strlen(command) == 1){
        list_all_Flights();
    }
    else{
        newFlight();
    }
}
*/

int getday(char *command){
    int i;
    for (i = 1; command[i] == ' ' || command[i] == '\t'; i++){
    }
    return i ;
}

int getmonth(char *command, int index){
    int i;
    for (i = index; command[i] != '-'; i++){
    }
    return i + 1;
}

int getyear(char*command, int index){
    int i;
    for (i = index; command[i] != '-'; i++){
    }
    return i + 1;
}

int validate(Date temp){
    if (temp.year < today.year){
        return 0;
    }
    if (temp.year == today.year){
        if (temp.month < today.month){
            return 0;
        }
        else if (temp.month == today.month){
            if (temp.day < today.day){
                return 0;
            }
            else if(temp.day == today.day){
                return 1;
            }
            else if (temp.day > today.day){
                return 1;
            }
        }
        else if (temp.month > today.month){
            return 1;
        }
    }
    else if (temp.year > today.year){
        if(temp.month > today.month){
            return 0;
        }
        else if (temp.month == today.month && temp.day > today.day){
            return 0;
        }
    }
    return 1;
}

void printdate(void){
    if (today.day < 10 && today.month < 10){
            printf("0%d-0%d-%d\n", today.day, today.month,today.year);
        }
        if (today.day < 10 && today.month > 10){
            printf("0%d-%d-%d\n", today.day, today.month,today.year);
        }
        if (today.day > 10 && today.month < 10){
            printf("%d-0%d-%d\n", today.day, today.month,today.year);
        }
        else{
            if (today.day > 10 && today.month > 10){
            printf("%d-%d-%d\n", today.day, today.month,today.year);
            }
        }
}

int day(char *command, int i){
    int digit1, digit2, newday;
    digit1 = command[i] - '0';
    digit2 = command[i+1] - '0';
    newday = digit1*10 + digit2;
    return newday;
}
int month(char *command, int i){
    int digit1, digit2, newmonth;
    digit1 = command[i] - '0';
    digit2 = command[i+1] - '0';
    newmonth = digit1*10 + digit2;
    return newmonth;
}
int year(char *command, int i){
    int digit1, digit2, digit3 , digit4, newyear;
    digit1 = command[i] - '0';
    digit2 = command[i+1] - '0';
    digit3 = command[i+2] - '0';
    digit4 = command[i+3] - '0';
    newyear = digit1*1000 + digit2*100 + digit3*10 + digit4;
    return newyear;
}
void changedate(char *command){
    int i;
    Date temp;
    i = getday(command);
    temp.day = day(command, i);
    i = getmonth(command, i);
    temp.month  = month(command, i);
    i = getyear(command, i);
    temp.year = year(command, i);
    if (validate(temp) == 1){
        today.day = temp.day;
        today.month = temp.month;
        today.year = temp.year;
        printdate();
    }
    else{
        printf("invalid date\n");
    }
}

int main(void){
    char command[COM_DIM];
    today.day = 1;
    today.month = 1;
    today.year = 2022;
    while (command[0]!= 'q'){
        scanf("%[^\n]%*c", command);
        switch (command[0]){
            case 'a':
                newApt(command);
                break;
            case 'l':
                listApt(command);
                break;
            /*case 'v':
                flight(command);
                break;*/
            case 't':
                changedate(command);
        }
    }
    return 0;
}

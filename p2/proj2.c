<<<<<<< HEAD
/*Project 2 made by Joao Maia, number 102428
IAED, Instituto Superior Tecnico*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define COM_DIM 65535
=======
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define COM_DIM 161
>>>>>>> a599caf2602e60e26b61a4b13a0a35dc9307b33f
#define ID_SIZE 4
#define COUNTRY_SIZE 31
#define CITY_SIZE 51
#define AIRPORTS_MAX 40
#define F_IDSIZE 7
#define FLIGHTS_MAX 30000
<<<<<<< HEAD
#define TRUE 1
#define FALSE 0


/*structures*/
typedef struct Reserves {
    char *id;
    int passangers;
    int flightindex;
    struct Reserves *before;
    struct Reserves *next;
} Reserves;
=======
>>>>>>> a599caf2602e60e26b61a4b13a0a35dc9307b33f


typedef struct Date{
    int day;
    int month;
    int year;
}Date;


typedef struct Hour{
    int hour;
    int minutes;
}Hour;


<<<<<<< HEAD
=======
Date today;


>>>>>>> a599caf2602e60e26b61a4b13a0a35dc9307b33f
typedef struct Flight{
    char id[F_IDSIZE];
    char departure[ID_SIZE];
    char arrival[ID_SIZE];
    Date departure_date;
    Hour departure_hour;
    Hour arrival_hour;
    Date arrival_date;
    Hour duration;
    int capacity;
<<<<<<< HEAD
    int number_of_passangers;
=======
>>>>>>> a599caf2602e60e26b61a4b13a0a35dc9307b33f
}Flight;


typedef struct Airport{
    char id[ID_SIZE];
    char country[COUNTRY_SIZE];
    char city[CITY_SIZE];
    int departures;
}Airport;


<<<<<<< HEAD
/*Global Variables*/
Reserves *head = NULL;


Reserves *tail = NULL;


Flight nullflight;


int number_of_flights = 0;


int number_of_reserves = 0;


Date today;


=======
>>>>>>> a599caf2602e60e26b61a4b13a0a35dc9307b33f
Flight list_flights[FLIGHTS_MAX];


Airport list_airports[AIRPORTS_MAX];

<<<<<<< HEAD
/*Functions*/
=======

>>>>>>> a599caf2602e60e26b61a4b13a0a35dc9307b33f
int Pow(int x, int y){    /* Pow: works as the funcion pow defined in math.h. Returns the result of x^y */
	int power = 1, i;
	for (i = 1; i <= y; ++i){
		power = power * x;
	}
	return power;
}


int day(char *command, int i){              /*day: Receives the string ponter command and an index that indicates where the day number starts, returns month day*/
    int digit1, digit2, day;
    digit1 = command[i] - '0';
    digit2 = command[i+1] - '0';
    day = digit1*10 + digit2;
    return day;
}


int month(char *command, int i){    /*month: Receives the string ponter command and an index that indicates where the month number starts, returns the day*/
    int digit1, digit2, month;
    digit1 = command[i] - '0';
    digit2 = command[i+1] - '0';
    month = digit1*10 + digit2;
    return month;
}


int year(char *command, int i){
    int digit1, digit2, digit3 , digit4, year;  /*year: Receives the string ponter command and an index that indicates where the year number starts, returns the year*/
    digit1 = command[i] - '0';
    digit2 = command[i+1] - '0';
    digit3 = command[i+2] - '0';
    digit4 = command[i+3] - '0';
    year = digit1*1000 + digit2*100 + digit3*10 + digit4;
    return year;
}


int equaldate(Date date1, Date date2){  /*equaldate: receives 2 Dates and returns 1 if they are equal and 0 if they are not equal*/
    if (date1.day == date2.day && date1.month == date2.month && date1.year == date2.year){
        return 1;
    } 
    return 0;
}


<<<<<<< HEAD
int dupfid(char *id, int tday, int tmonth, int tyear){  /*dupfid: receives a Flight ID, a day, a month and a year. Returns 1 if a flight with that Flight ID exists on that day*/
=======
int dupfid(char *id, int tday, int tmonth, int tyear){  /*dupfid: receives a Flight ID, a day, a month and a year. Returns 0 a flight with that Flight ID exists on that day*/
>>>>>>> a599caf2602e60e26b61a4b13a0a35dc9307b33f
    int i, equal, empty;
    Date date;
    date.day = tday;
    date.month = tmonth;
    date.year = tyear;
    for (i = 0; i < FLIGHTS_MAX; i++){
        equal = strcmp(list_flights[i].id, id);
        empty = strcmp(list_flights[i].id, "");
        if (empty == 0){
            return 0;
        }
        if (equal == 0 && equaldate(date, list_flights[i].departure_date) == 1){
            return 1;
        }
    }
    return 0;
}

<<<<<<< HEAD
int validatefid(char *id){  /*validatefid: receives a Flight ID and returns 1 if the id is valid and 0 if the id is not invalid*/
=======

int FlightbyId(char *id){   /*Flightbyid: receives a Flight ID and returns the flight position on List_airports*/
    int i, equal;
    for (i = 0; i < FLIGHTS_MAX; i++){
        equal = strcmp(list_flights[i].id, id);
        if (equal == 0){
            break;
        }
    }
    return i;
}


int validatefid(char *id){  /*validatefid: receives a Flight ID and returns 1 if the id is valid and 0 if the id is invalid*/
>>>>>>> a599caf2602e60e26b61a4b13a0a35dc9307b33f
    int i, len;
    len = strlen(id);
    for (i = 0; i < len; i++){
        if (0 <= i && i < 2){
            if (id[i] < 'A' || id[i] > 'Z'){
                return 0;
            }
        }
        if (i > 1){
            if (id[i] < '0' || id[i] > '9'){
                return 0;
            }
        }
    }
    return 1;
}


int getnext(char *command, int index){  /*getnext: receives a command and an index and returns the index of the next ocuppied position in command*/
    int i;
    for (i = index; command[i] == ' ' || command[i] == '\t'; i++){
    }
    return i;
}

int get_hour(char *command, int i){ /*get_hour: receives a command and the index of the position of the hours and returns the hour*/
    int digit1, digit2, hour;
    digit1 = command[i] - '0';
    digit2 = command[i+1] - '0';
    hour = digit1*10 + digit2;
    return hour;
}


int get_minutes(char *command, int i){  /*get_minutes: receives a command and the index of the position of the minutes and returns the minuts*/
    int digit1, digit2, minute;
    digit1 = command[i] - '0';
    digit2 = command[i+1] - '0';
    minute = digit1*10 + digit2;
    return minute;
}


int get_capacity(char *command, int index){ /*get_capacity: receives a command and the index of the capacity of the hours and returns the capacity*/
    int i = index, e, size, digitnumbers, digit, temp = 0;
    size = strlen(command);
    digitnumbers = size - i;
    for (e = digitnumbers; i < size; i++){
        digit = command[i] - '0';
        temp = temp + digit*Pow(10, e-1);
        e--;
    }
    return temp;
}


int dupId(char *id){ /*dupID: receives a Airport ID and returns 1 if the ID already exists in list_airports and 0 if doesn't exist*/ 
    int i, equal;
    for (i = 0; i < AIRPORTS_MAX; i++){
        equal = strcmp(id, list_airports[i].id);
        if (equal == 0){
            return 1;
        }
    }
    return 0;
}


int validId(char *id){  /*validID: receives a Airport ID and returns 1 if the id is valid*/
    int i;
    if (strcmp(list_airports[AIRPORTS_MAX - 1].id,"\000") != 0){
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


int getid(char *command, char *id, int index){  /*getid: receives the command, the id and an index of the first ID letter position. Returns the position of the next empty space*/
    int i = index, e = 0;
    for (i = index; command[i] != ' ' && command[i] != '\t'; i++){
        id[e] = command[i];
        e++;
    }
    return i;
}


int getcountry(char* command, char* country, int index){    /*getcountry: receives the command, the id and an index of the first country letter position. Returns the position of the next empty space*/
    int i, e = 0;
    for (i = index; command[i] != ' ' && command[i]!= '\t'; i++){
        country[e] = command[i];
        e++;
    }
    return i;
}


void getcity(char* command, char* city, int index){ /*getcity: receives the command, the id and an index of the first country letter position*/
    int i , e = 0, len;
    len = strlen(command);
    for (i = index; i < len; i++){
        city[e] = command[i];
        e++;
    }
}


void sort(char list[AIRPORTS_MAX][ID_SIZE], int size){  /*sort: receives an array of ID's and the number of ID's and sorts*/
    int i = 0, compare = 0, minors = 0;
    char temp[ID_SIZE] = "\0";
    /*compares i position id with i + 1 position id and if i position i > i + i, switch places. If i position < i + 1 position
        increments minors by 1 and if minors = size - 1 (number of comparations), the list is sorted and breaks the loop*/
    for (i = 1; i < size; i++){
        compare = strcmp(list[i-1], list[i]);   /*if >0 , list[i]>list[i+1] */
        if (minors == size-1){
            break;
        }
        if(compare > 0){
            minors = 0;
            strcpy(temp, list[i-1]);
            strcpy(list[i-1], list[i]);
            strcpy(list[i], temp);  
            if(i + 1 == size){
                i=0;
            }
        }
        if(compare < 0){
            minors++;
            if(i + 1 == size){
                i=0;
            }   
}   }   }


int AptbyId(char *id){  /*AptbyID: receives an Airport ID an id and returns his position in list_airports*/
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


void specific_list(char *com){  /*specific_list: receives a command and prints all asked airpots*/
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


void emptyl(){  /*emptyl: prints all airports in list_airports */
    int i = 0, empty = 0, size = 0, y = 0, z = 0, equalid = 0, citylen = 0, countrylen = 0;
    char idlist[AIRPORTS_MAX][ID_SIZE];
    /*copy all airports id to char idlist and increments the size, wich is how much airports there are in lis_airports*/
    for (i = 0; i < AIRPORTS_MAX; i++){
        empty = strcmp(list_airports[i].id, "");
        if (empty == 0){
            break;
        }
        strcpy(idlist[i], list_airports[i].id);
        size++;
    }
    sort(idlist, size);
    while( y < size){
        equalid = strcmp(idlist[y],list_airports[z].id);
        if (equalid == 0){
            citylen = strlen(list_airports[z].city);
            countrylen = strlen(list_airports[z].country);
            printf("%s %.*s %.*s %d\n", list_airports[z].id, citylen, list_airports[z].city, countrylen, list_airports[z].country, list_airports[z].departures);
            y++;
            z = 0;
        }
        else if (equalid != 0){
            z++;
        }
    }   
}      


Date get_date(char *command ,int i){    /*get_date: receives a command and the postiion of the hour. Returns the Date*/
    Date temp;
    temp.day = day(command, i);
    /*it increments i by 3 because there are 2 characters in the middle and the next number
        is at position + 3 */
    i += 3;
    temp.month = month(command, i);
    i += 3;
    temp.year = year(command, i);
    return temp;
}


void listApt(char *command){    /*lisapt: receives a command and calls the right funcion*/
    if (strlen(command) == 1){
        emptyl();
    }
    specific_list(command);
}


void emptyid(char *id){ /*emptyid: clears an Airport ID*/
    int i;
    for (i = 0; i != ID_SIZE; i++){
        id[i] = '\0';
    }
}


void emptycountry(char *country){   /*emptycountry: clears a country*/
    int i;
    for (i = 0; i != COUNTRY_SIZE; i++){
        country[i] = '\0';
    }
}

void emptycity(char *city){ /*emptcity: clears city*/
    int i;
    for (i = 0; i != CITY_SIZE; i++){
        city[i] = '\0';
    }
}


void newApt(char *command){ /*newApt: receives a command and */
    Airport apt;
    char id[ID_SIZE];
    char country[COUNTRY_SIZE];
    char city[CITY_SIZE];
    int i = 1 , empty;
    emptyid(id);
    emptycountry(country);
    emptycity(city);
    i = getnext(command, i);
    i = getid(command, id, i);
    i = getnext(command, i);
    i = getcountry(command, country, i);
    i = getnext(command, i);
    getcity(command, city, i);
    strcpy(apt.id, id);
    strcpy(apt.country, country);
    strcpy(apt.city, city);
    apt.departures = 0;
    if (validId(apt.id) == 1 ){
        for (i = 0 ; i < AIRPORTS_MAX; i++){
            empty = strcmp(list_airports[i].id, "\0\0\0");
            if (empty == 0){
                list_airports[i] = apt;
                printf("airport %.*s\n", ID_SIZE-1,list_airports[i].id);
                break;
            }
        }
    }
}


int validate(Date temp){    /* validate: receives a date and returns 1 if the date is valid*/
    if (temp.year < today.year){
        return 0;
    }
    else if (temp.year == today.year && temp.month < today.month){
        return 0;
    }
    else if (temp.year == today.year && temp.month == today.month && temp.day < today.day){
        return 0;
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


int validflight(Flight flight){ /*validflight: receives a flight and returns 1 if it is valid and prints the error*/
    int empty;
    if (validatefid(flight.id) == 0){
        printf("invalid flight code\n");
        return 0;
    }
    if (dupfid(flight.id, flight.departure_date.day, flight.departure_date.month, flight.departure_date.year) == 1){
        printf("flight already exists\n");
        return 0;
    }
    if (dupId(flight.arrival) == 0){
        printf("%s: no such airport ID\n", flight.arrival);
        return 0;
    }
    if (dupId(flight.departure) == 0){
        printf("%s: no such airport ID\n", flight.departure);
        return 0;
    }
    empty = strcmp(list_flights[FLIGHTS_MAX-1].id, "\000");
    if (empty != 0){
        printf("too many flights\n");
        return 0;
    }
    if (validate(flight.departure_date) == 0){
        printf("invalid date\n");
        return 0;
    }
    if (flight.duration.hour >= 12){
        if (flight.duration.minutes > 0){
            printf("invalid duration\n");
            return 0;
        }
    }
<<<<<<< HEAD
    if (flight.capacity < 10){
=======
    if (flight.capacity < 10 || flight.capacity > 100){
>>>>>>> a599caf2602e60e26b61a4b13a0a35dc9307b33f
        printf("invalid capacity\n");
    }
    return 1;
}


Hour get_arrival_hour(Hour departure_hour, Hour duration){  /*get_arrival_hour: reveives the departure hour and the flight durations and returns the arrival hour*/
    Hour arrival_hour;
    if (departure_hour.minutes + duration.minutes >= 60 && departure_hour.hour + duration.hour >= 23){
        arrival_hour.hour = departure_hour.hour + duration.hour + 1  - 24;
        arrival_hour.minutes = departure_hour.minutes + duration.minutes - 60;
        return arrival_hour;
    }
    else if(departure_hour.hour + duration.hour >= 24){
        arrival_hour.hour = departure_hour.hour + duration.hour - 24;
        arrival_hour.minutes = departure_hour.minutes + duration.minutes;
        return arrival_hour;
    }
    else if(departure_hour.minutes + duration.minutes >= 60){
        arrival_hour.hour = departure_hour.hour + duration.hour + 1;
        arrival_hour.minutes = departure_hour.minutes + duration.minutes - 60;
        return arrival_hour;
    }
    arrival_hour.hour = departure_hour.hour + duration.hour;
    arrival_hour.minutes = departure_hour.minutes + duration.minutes;
    return arrival_hour;
}


Date monthjan(Date actualdate){ /*monthjan: receives a date that has 31 days and changes the month or year if necessary. Returns the corrected date*/
    if (actualdate.day > 31){
        actualdate.day = 1;
        actualdate.month ++;
        if (actualdate.month > 12){
            actualdate.month = 1;
            actualdate.year ++;
        }
    }
    return actualdate;
}


Date monthmarch(Date actualdate){ /*monthmarch: receives a date that has 30 days and changes the month or year if necessary. Returns the corrected date*/
    if (actualdate.day > 30){
        actualdate.day = 1;
        actualdate.month ++;
    }
    return actualdate;
}


Date monthfeb(Date actualdate){ /*monthfeb: receives a date that has 28 days and changes the month or year if necessary. Returns the corrected date*/
    if (actualdate.day > 28){
            actualdate.day = 1;
            actualdate.month ++;
    }
    return actualdate;
}


int typemonth(Date actualdate){ /*type: receives a date and returns the month type*/
    if (actualdate.month == 1 || actualdate.month == 3 || actualdate.month == 5 || actualdate.month == 7 || actualdate.month == 8 || actualdate.month == 10 || actualdate.month == 12){
        return 31;
    }
    else if (actualdate.month == 4 || actualdate.month == 6 || actualdate.month == 9 || actualdate.month == 11){
        return 30;
    }
    else{
        return 28;
    }
}
Date get_arrival_date(Hour departure_hour, Hour arrival_hour, Date actualdate){ /*get_arrival_date: reveives the departure hour, arrival hour and departure date and returns the arrival date*/
    int type = 0;
    type++;
    if (arrival_hour.hour < departure_hour.hour){
        actualdate.day++;
    }
    type = typemonth(actualdate);
    if (typemonth(actualdate) == 31){
        return monthjan(actualdate);
    }
    else if (typemonth(actualdate) == 30){
        return monthmarch(actualdate);
    }
    else if (typemonth(actualdate) == 28){
        return monthfeb(actualdate);
    }
    return actualdate;
}


void newFlight(char *command){  /*newFlight: receives a command and creates a flight in list_flights*/
    Flight flight;
    int i = 0 , e = 0, valid = 0, empty = 0;
    for (i = 1; command[i] == ' ' || command[i] == '\t'; i++){
    }
    for (i = i; command[i] != ' ' && command[i] != '\t'; i++){
        if (e == F_IDSIZE){
            strcpy(flight.id, "aaaaa");
            break;
        }
        flight.id[e] = command[i];
        e++;
    }
    for (e = e; e < F_IDSIZE; e++){
        flight.id[e] = '\0';
    }
    e = 0;
    i = getnext(command, i);
    for (i = i; e < ID_SIZE; i++){
        flight.departure[e] = command[i];
        e++;
    }
    flight.departure[ID_SIZE-1] = '\0';
    e = 0;
    i = getnext(command, i);
    for (i = i; e < ID_SIZE; i++){
        flight.arrival[e] = command[i];
        e++;
    }
    flight.arrival[ID_SIZE-1] = '\0';
    i = getnext(command, i);
    flight.departure_date =  get_date(command, i);
    i += 10;
    i = getnext(command, i);
    flight.departure_hour.hour = get_hour(command,i);
    i += 3;
    flight.departure_hour.minutes = get_minutes(command, i);
    i += 3;
    i = getnext(command, i);
    flight.duration.hour = get_hour(command,i);
    i += 3;
    flight.duration.minutes = get_minutes(command, i);
    i += 3;
    i = getnext(command, i);
    flight.capacity = get_capacity(command, i);
    flight.arrival_hour = get_arrival_hour(flight.departure_hour, flight.duration);
    flight.arrival_date = get_arrival_date(flight.departure_hour, flight.arrival_hour, flight.departure_date);
<<<<<<< HEAD
    flight.number_of_passangers = 0;
=======
>>>>>>> a599caf2602e60e26b61a4b13a0a35dc9307b33f
    valid = validflight(flight);
    if(valid == 1){
        list_airports[AptbyId(flight.departure)].departures++;
        for (i = 0; i < FLIGHTS_MAX; i++){
            empty = strcmp(list_flights[i].id, "\0\0\0\0\0");
            if (empty == 0){
                list_flights[i] = flight;
<<<<<<< HEAD
                number_of_flights++;
=======
>>>>>>> a599caf2602e60e26b61a4b13a0a35dc9307b33f
                break;
            }
        }
    }
}



void printdate(Date date){ /*printdate: receives a date and prints it out*/
    printf("%02d-%02d-%02d", date.day, date.month,date.year);
}

void printhour(Hour hour){/*printhour: receives a hour and prints it out*/
    printf("%02d:%02d", hour.hour, hour.minutes);
}

void list_all_Flights(void){    /*list_all_flights: prints all flights*/
    int i, empty;
    /*runs through list_flight[i].id and prints all existing flights*/
    for (i = 0; i < FLIGHTS_MAX; i++){
        empty = strcmp(list_flights[i].id, "\0\0\0");
        if (empty == 0){
            break;
        }
        printf("%s %.3s %.3s ",list_flights[i].id, list_flights[i].departure, list_flights[i].arrival);
        printdate(list_flights[i].departure_date);
        printf(" ");
        printhour(list_flights[i].departure_hour);
        printf("\n");
    }
}

void flight(char * command){ /*flight: receives a ccommand and calls the right funcion: l->list_all_Flighs; if l (...) -> creates a new flight*/
    if (strlen(command) == 1){
        list_all_Flights();
    }
    else{
        newFlight(command);
    }
}



void changedate(char *command){ /*changedate: receives a command and changes today date*/
    int i = 1;
    Date temp;
    for (i = 1; command[i]== ' '; i++){
    }
    temp = get_date(command, i);
    if (validate(temp) == 1){
        today.day = temp.day;
        today.month = temp.month;
        today.year = temp.year;
        printdate(temp);
        printf("\n");
    }
    else{   
        printf("invalid date\n");
    }
}


int comparate_date(Date date1, Date date2){ /*comparate_date: receives 2 dates and returns 2 if date 1 > date 2, 1 if date 2 > date 1 and 0 if date 1 == date 2 */
    if (date1.year < date2.year){
            return 1;
        }
        else if (date1.year == date2.year && date1.month < date2.month){
            return 1;
        }
        else if (date1.year == date2.year && date1.month == date2.month && date1.day < date2.day){
            return 1;
        }
    else if(date1.year > date2.year){
        if(date1.month > date2.month){
            return 2;
        }
        else if (date1.month == date2.month && date1.day > date2.day){
            return 2;
        }
    }
    else if(date1.year == date2.year && date1.month == date2.month && date1.day == date2.day){
        return 0;
    }
    return 2;
}

int comparate_time(Hour time1, Hour time2){ /*comparate_date: receives 2 different hours and returns 1 if hour1 > hour2 and 0 if hour2 > hour1 */
    if (time1.hour > time2.hour){
        return 1;
    }
    else if(time1.hour == time2.hour && time1.minutes > time2.minutes){
        return 1;
    }
    return 0;
}


void sortbydatepfunc(Flight *flightlistptr ,Flight flist[FLIGHTS_MAX], int size){   /*sortbydatepfunc: receibes a flight list pointer, a flights list and the quantity of flihts. Sorts the list by the most old departure date*/
    int i = 0, minors = 0;
    Flight flightlist[FLIGHTS_MAX];
    Flight temp;
    for (i = 0; i < size; i++){
        flightlist[i] = flist[i];
    } 
    for (i = 1; i < size; i++){
        if (minors == size - 1){
            break;
        }
        if (comparate_date(flightlist[i-1].departure_date, flightlist[i].departure_date) == 0){
            if (comparate_time(flightlist[i-1].departure_hour, flightlist[i].departure_hour) == 1){
                temp = flightlist[i];
                flightlistptr[i] = flightlist[i-1];
                flightlistptr[i-1] = temp;
                flightlist[i] = flightlist[i-1];
                flightlist[i-1] = temp;
                minors = 0;
                if (i + 1 == size){
                    i = 0;
                }
            }
            else if (comparate_time(flightlist[i-1].departure_hour, flightlist[i].departure_hour) == 0){
                if (i + 1 == size){
                    i = 0;
                    minors++;
                }
                else{
                    minors ++;
                }
            }
        }
        else if(comparate_date(flightlist[i-1].departure_date, flightlist[i].departure_date) == 1){
            minors ++;
            if (i + 1 == size){
                    i = 0;
            }
        }
        else{
            temp = flightlist[i];
            flightlistptr[i] = flightlist[i-1];
            flightlistptr[i-1] = temp;
            flightlist[i] = flightlist[i-1];
            flightlist[i-1] = temp;
            minors = 0;
            if (i + 1 == size){
                i = 0;
                minors = 0;
            }
        }
    }
}


void sortbydatecfunc(Flight *flightlistptr ,Flight flist[FLIGHTS_MAX], int size){   /*sortbydatecfunc: receives a flight list pointer, a flights list and the quantity of flihts. Sorts the list by the most old arrival date*/
    int i = 0, minors = 0;
    Flight flightlist[FLIGHTS_MAX];
    Flight temp;
    for (i = 0; i < size; i++){
        flightlist[i] = flist[i];
    } 
    for (i = 1; i < size; i++){
        if (minors == size - 1){
            break;
        }
        if (comparate_date(flightlist[i-1].arrival_date, flightlist[i].arrival_date) == 0){
            if (comparate_time(flightlist[i-1].arrival_hour, flightlist[i].arrival_hour) == 1){
                /*changes the position of flight i to i+1 and of flight i+1 to i*/
                temp = flightlist[i];
                flightlistptr[i] = flightlist[i-1];
                flightlistptr[i-1] = temp;
                flightlist[i] = flightlist[i-1];
                flightlist[i-1] = temp;
                minors = 0;                
                if (i + 1 == size){
                    i = 0;
                }
            }
            else if (comparate_time(flightlist[i-1].arrival_hour, flightlist[i].arrival_hour) == 0){
                minors++;
                if (i + 1 == size){
                    i = 0;
                }
            }
        }
        else if(comparate_date(flightlist[i-1].arrival_date, flightlist[i].arrival_date) == 1){
            minors ++;
            if (i + 1 == size){
                i = 0;
            }
        }
        else{
            /*changes the position of flight i to i+1 and of flight i+1 to i*/
            temp = flightlist[i];
            flightlistptr[i] = flightlist[i-1];
            flightlistptr[i-1] = temp;
            flightlist[i] = flightlist[i-1];
            flightlist[i-1] = temp;
            minors = 0;
            if (i + 1 == size){
                i = 0;
            }
        }
    }
}


void listp(char *id){   /*receives an Apirport Id and prints all flights departing or departed from it*/
    Flight flightslist[FLIGHTS_MAX];
    int i = 0, equal = 0, e = 0, empty;
    /*goes through list_flights list and adds to flightslist the flight id that
        departures from the ID's airport*/
    for (i = 0; i < FLIGHTS_MAX; i++){
        empty =strcmp(list_flights[i].departure, "");
        if (empty == 0){
            break;
        }
        equal = strcmp(id, list_flights[i].departure);
        if (equal == 0){
            flightslist[e] = list_flights[i];
            e++;
        }
    }
    sortbydatepfunc(flightslist, flightslist, e);
    for (i = 0; i < e; i++){
        printf("%s %.3s ",flightslist[i].id, flightslist[i].arrival);
        printdate(flightslist[i].departure_date);
        printf(" ");
        printhour(flightslist[i].departure_hour);
        printf("\n");
    }
}


void pfunc(char *command){  /*pfunc: receives a command and if the airport exists, calls listp*/
    int i = 1, e = 0, equal, exists;
    char id[ID_SIZE];
    i = getnext(command, i);
    /*gets airport's ID*/
    for (i = i; e < ID_SIZE; i++){
        id[e] = command[i];
        e++;
    }
    id[3] = '\0';
    /*verifies if that airport exists*/
    for (i = 0; i < AIRPORTS_MAX; i++){
        equal = strcmp(id, list_airports[i].id);
        if (equal == 0){
            exists = 1;
            break;
        }
        else{
            exists = 0;
        }
    }
    if (exists == 1){
        listp(id);
    }
    else{
        printf("%.3s: no such airport ID\n", id);}
}

void listc(char *id){   /*listc: receives an Apirport Id and prints all flights departing or departed from it*/
    Flight flightslist[FLIGHTS_MAX];
    int i = 0, equal = 0, e = 0, empty;
    /*go through list_flights list and adds to flightslist the flight id that
        arrivals at ID's airport*/
    for (i = 0; i < FLIGHTS_MAX; i++){
        empty =strcmp(list_flights[i].arrival, "");
        if (empty == 0){
            break;
        }
        equal = strcmp(id, list_flights[i].arrival);
        if (equal == 0){
            flightslist[e] = list_flights[i];
            e++;
        }
    }
    sortbydatecfunc(flightslist, flightslist, e);
    for (i = 0; i < e; i++){
        printf("%s %.3s ",flightslist[i].id, flightslist[i].departure);
        printdate(flightslist[i].arrival_date);
        printf(" ");
        printhour(flightslist[i].arrival_hour);
        printf("\n");
    }
}


void cfunc(char *command){  /*cfunc: receives a command and if the airport exists, calls listp*/
    int i = 1, e = 0, equal, exists;
    char id[ID_SIZE];
    i = getnext(command, i);
    /*gets airport's ID*/
    for (i = i; e < ID_SIZE; i++){
        id[e] = command[i];
        e++;
    }
    id[3] = '\0';
    /*verifies if that airports exists*/
    for (i = 0; i < AIRPORTS_MAX; i++){
        equal = strcmp(id, list_airports[i].id);
        if (equal == 0){
            exists = 1;
            break;
        }
        else{
            exists = 0;
        }
    }
    if (exists == 1){
        listc(id);
    }
    else{
        printf("%.3s: no such airport ID\n", id);}
}


<<<<<<< HEAD
int getflight(char *id, Date date){ /*getflight: returns the Index of the flight with that id and departure date*/
    int i = 0, equal = 0;
    for( i = 0; i < FLIGHTS_MAX ; i++){
        equal = strcmp(list_flights[i].id, id);
        if (equal == 0 && equaldate(date, list_flights[i].departure_date) == 1){
            return i;
        }
    }
    return i;
}


int validReserveCode(char *reservecode, int codesize){ /*validReserveCode: Returns 1 if the reserve is valid*/
    int i = 0;
    if (codesize < 10){
        return FALSE;
    }
    for (i = 0; i < codesize; i++){
        if (reservecode[i] < '0' || reservecode[i] > 'Z'){
            return FALSE;
        }
        else if(reservecode[i] < 'A' && reservecode[i] > '9'){
            return FALSE;
        }
    }
    return TRUE;
}


int duplicatedreservationcode(char *reservecode){
    int equal = 0;
    Reserves *temp;
    for (temp = head; temp != NULL; temp = temp->next){
        equal = strcmp(reservecode, temp->id);
        if (equal == 0){
            return TRUE;
        }
    }
    return FALSE;
}


int validReserve(char *fid, Date date, char *reservecode, int passangers, int codesize){ /*validReserve: Returns 1 if the reserve is valid and prints the errors if the reserve is not valid*/
    Flight tempflight = list_flights[getflight(fid, date)];
    if (validReserveCode(reservecode, codesize) == FALSE){
        printf("invalid reservation code\n");
        return FALSE;
    }
    else if (dupfid(fid, date.day, date.month, date.year) == FALSE){
        printf("%s: flight does not exist\n", fid);
        return FALSE;
    }
    else if (duplicatedreservationcode(reservecode) == TRUE){
        printf("%s: flight reservation already used\n", reservecode);
        return FALSE;
    }
    else if (passangers + tempflight.number_of_passangers > tempflight.capacity){
        printf("too many reservations\n");
        return FALSE;
    }
    else if (validate(date) == FALSE){
        printf("invalid date\n");
        return FALSE;
    }
    else if (passangers < 0){
        printf("invalid passenger number\n");
        return FALSE;
    }
    return TRUE;
}

void printReserves(int flightindex){ /*printReserves: prints all reserves of a specific flight*/
    Reserves *temp;
    temp = head;
    if (validate(list_flights[flightindex].departure_date) == TRUE){
        for (temp = head; temp != NULL; temp = temp->next){
            if (temp->flightindex == flightindex){
                printf("%s %d\n", temp->id, temp->passangers);
            }
        }
    }
    else{
        printf("invalid date\n");
    }
}

Reserves *create_Reserve(char *reservecode, int passangers, int flightindex){ /*create_Reserve: creates a reserve*/
    Reserves *final = malloc(sizeof(Reserves));
    final->id = reservecode;
    final->passangers = passangers;
    final->flightindex = flightindex;
    final->next = NULL;
    final->before = NULL;
    return final;
}


void insert_at_the_end(Reserves *Reserve_to_be_inserted){ /*insert_at_the_end: inserts a Reserve at the end of the list*/
    if (number_of_reserves == 1){
    Reserve_to_be_inserted->before = tail;
    Reserve_to_be_inserted->next = NULL;
    tail = Reserve_to_be_inserted;
    }
    else{
    Reserve_to_be_inserted->before = tail;
    Reserve_to_be_inserted->next = NULL;
    tail->next = Reserve_to_be_inserted;
    tail = Reserve_to_be_inserted;
    }
}


void insert_at_the_beginning(Reserves *Reserve_to_be_inserted){ /*insert_at_the_beginning: inserts a Reserve at the beginning of the list*/
    if(number_of_reserves == 1){
        head->next = tail;
        tail = head;
        Reserve_to_be_inserted->next = head;
        Reserve_to_be_inserted->before = NULL;
        head = Reserve_to_be_inserted;
        tail -> before = head;
    }
    else{
        Reserve_to_be_inserted->next = head;
        Reserve_to_be_inserted->before = NULL;
        head = Reserve_to_be_inserted;
    }
}


void insert_before(Reserves *Reserve_to_insert_before, Reserves *Reserve_to_be_inserted){ /*insert_before: inserts a Reserve before a given reserve*/
    Reserve_to_insert_before->before->next = Reserve_to_be_inserted;
    Reserve_to_be_inserted->before = Reserve_to_insert_before->before;
    Reserve_to_be_inserted->next = Reserve_to_insert_before;
    Reserve_to_insert_before->before = Reserve_to_be_inserted;
}


void insert_Reserve(Reserves *reserveToInsert){ /*insert_Reserve: receives a reserve and calls the right funcion to insert it*/
    int equal = 0, i = 0;
    Reserves *temp;
    if (head == NULL){
        head = reserveToInsert;
        head->next = tail;
        head->before = NULL;
        number_of_reserves++;
    }
    else{
        for (temp = head; temp != NULL; temp = temp->next, i++){
            equal = strcmp(reserveToInsert->id, temp->id);
            if (equal < 0){
                if (i == 0){
                    insert_at_the_beginning(reserveToInsert);
                    number_of_reserves ++;
                }
                else{
                    insert_before(temp, reserveToInsert);
                    number_of_reserves ++;
                }
            }
        }
        if (i == number_of_reserves){
            insert_at_the_end(reserveToInsert);
            number_of_reserves ++;
        }
    }
}


void reserve(char *command){ /*reserve: treats the command string to decide if it is going to print or if it is goingh to add a Reserve*/
    int i = 1, last = 0, len = strlen(command), codesize = 0, passangers = 0, flightindex = 0;
    char fid[ID_SIZE + 1], *reservecode;
    Date date;
    Reserves *newReserve;
    i = getnext(command, i);
    i = getid(command, fid, i);
    i = getnext(command, i);
    date = get_date(command, i);
    i += 10;
    flightindex = getflight(fid, date);
    if (i == len){
        printReserves(flightindex);
    }
    else{
        i = getnext(command, i);
        last = i;
        for (i = i; command[i] != ' ' && command[i] != '\t'; i++){
            codesize ++;
        }
        reservecode = malloc(sizeof(char) * (codesize + 1));
        i = getnext(command, i);
        passangers = get_capacity(command, i);
        getid(command, reservecode, last);
        if (validReserve(fid, date, reservecode, passangers, codesize) == TRUE){
            newReserve = create_Reserve(reservecode, passangers, flightindex);
            insert_Reserve(newReserve);
            list_flights[flightindex].number_of_passangers += passangers;
        }
    }
}


void destroy(){
    Reserves *temp, *nexttemp;
    for (temp = head; temp != NULL; temp = nexttemp){
        nexttemp = temp->next;
        free(temp->id);
        free(temp);
    }
}


void deletereserve(Reserves *reserve){
    Reserves *temp;
    temp = reserve;
    if(reserve == head && number_of_reserves == 1){
        head = NULL;
    }
    else if (reserve == head){
        head = reserve->next;
        head->before = NULL;
    }
    else if (reserve == tail){
        tail = reserve;
        tail->next = NULL;
    }
    else{
        reserve = reserve->next;
        reserve->before = temp->before;
    }
}


void lesspassangers(Reserves *reserve, int flightindex){
    list_flights[flightindex].number_of_passangers = list_flights[flightindex].number_of_passangers - reserve->passangers;
}


void deletereservesbyindex(int flightpos){
    Reserves *temp;
    for (temp = head; temp != NULL; temp = temp->next){
        if (temp->flightindex == flightpos){
            lesspassangers(temp, temp->flightindex);
            deletereserve(temp);
            number_of_reserves--;
        }
        if (temp->flightindex > flightpos){
            temp->flightindex--;
        }
    }
}


void deleteflights(char *code){
    int  i = 1, equal = 0, number_of_deleted_flights = 0, initialflightnum = number_of_flights;
    while (i  <= initialflightnum){
        equal = strcmp(code, list_flights[i-1].id);
        if (initialflightnum == 0){
            printf("not found\n");
            break;
        }
        if (initialflightnum - i + 1 >= number_of_deleted_flights && i != 1){
            list_flights[i-1] = nullflight;
            i++;
        }
        else if (equal == 0 && number_of_flights == 1){
            deletereservesbyindex( i-1);
            list_flights[i-1] = nullflight;
            deletereservesbyindex( i-1);
            number_of_deleted_flights++;
            number_of_flights--;
            i++;
        }
        
        else if (equal == 0){
            deletereservesbyindex( i-1 );
            list_flights[i-1] = list_flights[i];
            number_of_deleted_flights++;
            number_of_flights--;
            i++;
        }
        else{
            i++;
        }
    }
    if (number_of_deleted_flights == 0){
        printf("not found\n");
    }
}


Reserves *findreserve(char *code){
    int equal = 0;
    Reserves *temp;
    for (temp = head; temp != NULL; temp = temp->next){
        equal = strcmp(code, temp->id);
        if (equal == 0){
            return temp;
        }
    }
    return temp;
}


void deletereservebycode(char *code){
    int flightpos = 0;
    Reserves *temp, *reservetodelete;
    reservetodelete = findreserve(code);
    if (reservetodelete == NULL){
        printf("not found\n");
    }
    else{
        flightpos = reservetodelete->flightindex;
        for (temp = head; temp != NULL; temp = temp->next){
            if (reservetodelete == temp){
                lesspassangers(temp, temp->flightindex);
                deletereserve(temp);
                number_of_reserves--;
            }
            if (temp->flightindex > flightpos){
                temp->flightindex--;
            }
        }
    }
}

void delete(char *command){
    int i = 1, last = 0, len = strlen(command), codesize = 0;
    char *code;
    i = getnext(command, i);
    last = i;
    codesize = len -last;
    if (codesize >F_IDSIZE && codesize < 10){
        printf("not found\n");
    }
    else{
        code = malloc(sizeof(char)*(codesize+1));
        i = getid(command, code, i);
        if (codesize <= F_IDSIZE){
            deleteflights(code);
            free(code);
        }
        else if (codesize >= 10){
            deletereservebycode(code);
            free(code);
        }
        else{
            free(code);
        }
    }
}


=======
>>>>>>> a599caf2602e60e26b61a4b13a0a35dc9307b33f
int main(void){
    char command[COM_DIM];
    today.day = 1;
    today.month = 1;
    today.year = 2022;
<<<<<<< HEAD
    command[0] = ' ';
    while (command[0]){
=======
    command[0] = '\0';
    while (command[0]!= 'q'){
>>>>>>> a599caf2602e60e26b61a4b13a0a35dc9307b33f
        fflush(stdin);
        scanf("%[^\n]%*c", command);
          switch (command[0]){
            case 'a':
                newApt(command);
                break;
            case 'l':
                listApt(command);
                break;
            case 'v':
                flight(command);
                break;
            case 'p':
                pfunc(command);
                break;
            case 't':
                changedate(command);
                break;
            case 'c':
                cfunc(command);
                break;
<<<<<<< HEAD
            case 'r':
                reserve(command);
                break;
            case 'e':
                delete(command);
                break;
            case 'q':
                destroy();
                exit(0);
=======
>>>>>>> a599caf2602e60e26b61a4b13a0a35dc9307b33f
          }
    }
    return 0;
}
    
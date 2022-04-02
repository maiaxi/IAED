#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define COM_DIM 161
#define ID_SIZE 4
#define COUNTRY_SIZE 31
#define CITY_SIZE 51
#define AIRPORTS_MAX 40
#define F_IDSIZE 7
#define FLIGHTS_MAX 30000


typedef struct Date{
    int day;
    int month;
    int year;
}Date;


typedef struct Hour{
    int hour;
    int minutes;
}Hour;


Date today;


typedef struct Flight{
    char id[F_IDSIZE];
    char departure[ID_SIZE];
    char arrival[ID_SIZE];
    Date date;
    Hour departure_hour;
    Hour arrival_hour;
    Date arrival_date;
    Hour duration;
    int capacity;
}Flight;


typedef struct Airport{
    char id[ID_SIZE];
    char country[COUNTRY_SIZE];
    char city[CITY_SIZE];
    int departures;
}Airport;


Flight list_flights[FLIGHTS_MAX];


Airport list_airports[AIRPORTS_MAX];


int Pow(int x, int y){    /* Function pow that works as the funcion pow defined in math.h. Returns the result of x^y*/
	int power = 1, i;
	for (i = 1; i <= y; ++i){
		power = power * x;
	}
	return power;
}


int day(char *command, int i){
    int digit1, digit2, day;
    digit1 = command[i] - '0';
    digit2 = command[i+1] - '0';
    day = digit1*10 + digit2;
    return day;
}


int month(char *command, int i){
    int digit1, digit2, month;
    digit1 = command[i] - '0';
    digit2 = command[i+1] - '0';
    month = digit1*10 + digit2;
    return month;
}


int year(char *command, int i){
    int digit1, digit2, digit3 , digit4, year;
    digit1 = command[i] - '0';
    digit2 = command[i+1] - '0';
    digit3 = command[i+2] - '0';
    digit4 = command[i+3] - '0';
    year = digit1*1000 + digit2*100 + digit3*10 + digit4;
    return year;
}

int equaldate(Date date1, Date date2){
    if (date1.day == date2.day && date1.month == date2.month && date1.year == date2.year){
        return 1;
    } 
    return 0;
}
int dupfid(char *id, int tday, int tmonth, int tyear){
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
        if (equal == 0 && equaldate(date, list_flights[i].date) == 1){
            return 1;
        }
    }
    return 0;
}

int FlightbyId(char *id){
    int i, equal;
    for (i = 0; i < FLIGHTS_MAX; i++){
        equal = strcmp(list_flights[i].id, id);
        if (equal == 0){
            break;
        }
    }
    return i;
}


int validatefid(char *id){
    int i, len;
    len = strlen(id);
    for (i = 0; i < len; i++){
        if (0 <= i && i < 2){
            if (id[i] < 65 || id[i] > 90){
                return 0;
            }
        }
        if (i > 1){
            if (id[i] < 48 || id[i] > 57){
                return 0;
            }
        }
    }
    return 1;
}


int getnext(char *command, int index){
    int i;
    for (i = index; command[i] == ' ' || command[i] == '\t'; i++){
    }
    return i;
}

int get_hour(char *command, int i){
    int digit1, digit2, hour;
    digit1 = command[i] - '0';
    digit2 = command[i+1] - '0';
    hour = digit1*10 + digit2;
    return hour;
}


int get_minutes(char *command, int i){
    int digit1, digit2, minute;
    digit1 = command[i] - '0';
    digit2 = command[i+1] - '0';
    minute = digit1*10 + digit2;
    return minute;
}


int get_capacity(char *command, int index){
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

int getid(char *command, char *id,int index){
    int i = index, e = 0;
    for (i = index; command[i] != ' ' && command[i] != '\t'; i++){
        id[e] = command[i];
        e++;
    }
    return i;
}


int getcountry(char* command, char* country, int index){
    int i, e = 0;
    for (i = index; command[i] != ' ' && command[i]!= '\t'; i++){
        country[e] = command[i];
        e++;
    }
    return i;
}


void getcity(char* command, char* city, int index){
    int i , e = 0, len;
    len = strlen(command);
    for (i = index; i < len; i++){
        city[e] = command[i];
        e++;
    }
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
}   }   }

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
    int i = 0, e = 0, empty, size = 0, y = 0,z = 0, equalid = 0, citylen, countrylen;
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

Date get_date(char *command ,int i){
    Date temp;
    temp.day = day(command, i);
    i += 3;
    temp.month = month(command, i);
    i += 3;
    temp.year = year(command, i);
    return temp;
}


void listApt(char *command){
    if (strlen(command) == 1){
        emptyl();
    }
    else{
        specific_list(command);
    }
}


void emptyid(char *id){
    int i;
    for (i = 0; i != ID_SIZE; i++){
        id[i] = '\0';
    }
}


void emptycountry(char *country){
    int i;
    for (i = 0; i != COUNTRY_SIZE; i++){
        country[i] = '\0';
    }
}

void emptycity(char *city){
    int i;
    for (i = 0; i != CITY_SIZE; i++){
        city[i] = '\0';
    }
}
void newApt(char *command){
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

int validate(Date temp){
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

int validflight(Flight flight){
    int empty;
    if (validatefid(flight.id) == 0){
        printf("invalid flight code\n");
        return 0;
    }
    if (dupfid(flight.id, flight.date.day, flight.date.month, flight.date.year) == 1){
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
    if (validate(flight.date) == 0){
        printf("invalid date\n");
        return 0;
    }
    if (flight.duration.hour >= 12){
        if (flight.duration.minutes > 0){
            printf("invalid duration\n");
            return 0;
        }
    }
    if (flight.capacity < 10 || flight.capacity > 100){
        printf("invalid capacity\n");
    }
    return 1;
}


Hour get_arrival_hour(Hour departure_hour, Hour duration){
    Hour arrival_hour;
    if (departure_hour.minutes + duration.minutes >= 60 && departure_hour.hour + duration.hour >= 24){
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


Date get_arrival_date(Hour departure_hour, Hour arrival_hour, Date actualdate){
    if (arrival_hour.hour < departure_hour.hour){
        actualdate.day++;
        if (actualdate.month == 1 || actualdate.month == 3 || actualdate.month == 5 || actualdate.month == 7 || actualdate.month == 8 || actualdate.month == 10 || actualdate.month == 12){
            if (actualdate.day > 31){
                actualdate.day = 1;
                actualdate.month ++;
                if (actualdate.month > 12){
                    actualdate.month = 1;
                    actualdate.year ++;
                }
            }
        }
        if (actualdate.month == 4 || actualdate.month == 6 || actualdate.month == 9 || actualdate.month == 11){
            if (actualdate.day > 30){
                actualdate.day = 1;
                actualdate.month ++;
                if (actualdate.month > 12){
                    actualdate.year ++;
                }
            }
        }
        if (actualdate.month == 2){
            if (actualdate.day > 28){
                actualdate.day = 1;
                actualdate.month ++;
                if (actualdate.month > 12){
                    actualdate.month = 1;
                    actualdate.year ++;
                }
            }
        }
    }
    return actualdate;
}


void newFlight(char *command){
    Flight flight;
    int i = 0 , e = 0, valid, empty;
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
    flight.date =  get_date(command, i);
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
    flight.arrival_date = get_arrival_date(flight.departure_hour, flight.arrival_hour, flight.date);
    valid = validflight(flight);
    if(valid == 1){
        for (i = 0; i < FLIGHTS_MAX; i++){
            empty = strcmp(list_flights[i].id, "\0\0\0\0\0");
            if (empty == 0){
                list_flights[i] = flight;
                break;
            }
        }
    }
}


void printdate(Date date){
    printf("%02d-%02d-%02d", date.day, date.month,date.year);
}

void printhour(Hour hour){
    printf("%02d:%02d", hour.hour, hour.minutes);
}

void list_all_Flights(void){
    int i, empty;
    for (i = 0; i < FLIGHTS_MAX; i++){
        empty = strcmp(list_flights[i].id, "\0\0\0");
        if (empty == 0){
            break;
        }
        printf("%s %.3s %.3s ",list_flights[i].id, list_flights[i].departure, list_flights[i].arrival);
        printdate(list_flights[i].date);
        printf(" ");
        printhour(list_flights[i].departure_hour);
        printf("\n");
    }
}


void flight(char * command){
    if (strlen(command) == 1){
        list_all_Flights();
    }
    else{
        newFlight(command);
    }
}


void changedate(char *command){
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


int comparate_date(Date date1, Date date2){             /*returns 2 if date 1 > date 2, 1 if date 2 > date 1 and 0 if date 1 == date 2 */
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

int comparate_time(Hour time1, Hour time2){             /*comparatetimes returns 1 if time1 > time 2*/
    if (time1.hour > time2.hour){
        return 1;
    }
    else if(time1.hour == time2.hour && time1.minutes > time2.minutes){
        return 1;
    }
    return 0;
}


void sortbydatepfunc(Flight *flightlistptr ,Flight flist[FLIGHTS_MAX], int size){
    int i = 0, minors;
    Flight flightlist[FLIGHTS_MAX];
    Flight temp;
    for (i = 0; i < size; i++){
        flightlist[i] = flist[i];
    } 
    for (i = 0; i < size; i++){
        if (minors == size - 1){
            break;
        }
        if (comparate_date(flightlist[i].date, flightlist[i+1].date) == 0){
            if (comparate_time(flightlist[i].departure_hour, flightlist[i+1].departure_hour) == 1){
                if (i + 1 == size){
                    i = -1;
                }
                else{
                    temp = flightlist[i+1];
                    flightlistptr[i+1] = flightlist[i];
                    flightlistptr[i] = temp;
                    flightlist[i+1] = flightlist[i];
                    flightlist[i] = temp;
                    minors = 0;
                }
            }
            else{
                if (i + 1 == size){
                    i = -1;
                    minors++;
                }
                else{
                    minors ++;
                }
            }
        }
        else if(comparate_date(flightlist[i].date, flightlist[i+1].date) == 1){
            minors ++;
            if (i + 1 == size){
                    i = -1;
            }
        }
        else{
            if (i + 1 == size){
                i = -1;
                minors = 0;
            }
            else{
                temp = flightlist[i+1];
                flightlistptr[i+1] = flightlist[i];
                flightlistptr[i] = temp;
                flightlist[i+1] = flightlist[i];
                flightlist[i] = temp;
                minors = 0;
            }
        }
    }
}


void sortbydatecfunc(Flight *flightlistptr ,Flight flist[FLIGHTS_MAX], int size){
    int i = 0, minors;
    Flight flightlist[FLIGHTS_MAX];
    Flight temp;
    for (i = 0; i < size; i++){
        flightlist[i] = flist[i];
    } 
    for (i = 0; i < size; i++){
        if (minors == size - 1){
            break;
        }
        if (comparate_date(flightlist[i].arrival_date, flightlist[i+1].arrival_date) == 0){
            if (comparate_time(flightlist[i].arrival_hour, flightlist[i+1].arrival_hour) == 1){
                if (i + 1 == size){
                    i = -1;
                }
                else{
                    temp = flightlist[i+1];
                    flightlistptr[i+1] = flightlist[i];
                    flightlistptr[i] = temp;
                    flightlist[i+1] = flightlist[i];
                    flightlist[i] = temp;
                    minors = 0;
                }
            }
            else if (comparate_time(flightlist[i].arrival_hour, flightlist[i+1].arrival_hour) == 0){
                if (i + 1 == size){
                    i = -1;
                    minors++;
                }
                else{
                    minors ++;
                }
            }
        }
        else if(comparate_date(flightlist[i].arrival_date, flightlist[i+1].arrival_date) == 1){
            minors ++;
            if (i + 1 == size){
                    i = -1;
            }
        }
        else{
            if (i + 1 == size){
                i = -1;
                minors = 0;
            }
            else{
                temp = flightlist[i+1];
                flightlistptr[i+1] = flightlist[i];
                flightlistptr[i] = temp;
                flightlist[i+1] = flightlist[i];
                flightlist[i] = temp;
                minors = 0;
            }
        }
    }
}


void listp(char *id){
    Flight flightslist[FLIGHTS_MAX];
    int i = 0, equal = 0, e = 0, empty;
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
        printdate(flightslist[i].date);
        printf(" ");
        printhour(flightslist[i].departure_hour);
        printf("\n");
    }
}

void pfunc(char *command){
    int i = 1, e = 0, equal, exists;
    char id[ID_SIZE];
    i = getnext(command, i);
    for (i = i; e < ID_SIZE; i++){
        id[e] = command[i];
        e++;
    }
    id[3] = '\0';
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

void listc(char *id){
    Flight flightslist[FLIGHTS_MAX];
    int i = 0, equal = 0, e = 0, empty;
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


void cfunc(char *command){
    int i = 1, e = 0, equal, exists;
    char id[ID_SIZE];
    i = getnext(command, i);
    for (i = i; e < ID_SIZE; i++){
        id[e] = command[i];
        e++;
    }
    id[3] = '\0';
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


int main(void){
    char command[COM_DIM];
    today.day = 1;
    today.month = 1;
    today.year = 2022;
    while (command[0]!= 'q'){
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
          }
    }
    return 0;
}
    
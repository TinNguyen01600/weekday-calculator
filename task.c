//This file contains all the task functions necessary for the program
#include "mylib.h"

void change_to_wday(int n)
{
  switch(n){
    case 1: printf("Sunday"); break;
    case 2: printf("Monday"); break;
    case 3: printf("Tuesday"); break;
    case 4: printf("Wednesday"); break;
    case 5: printf("Thursday"); break;
    case 6: printf("Friday"); break;
    case 0: printf("Saturday"); break;
  }
}

void read_date(struct Date *search){
    char c1,c2;
    int day, month;
    int value = 0;
    char input[100];
    while (value == 0){
        printf("Enter a date (format dd/mm/yyyy): ");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%d%c%d%c", &day, &c1, &month, &c2);
        if((int)c1 != 10 ){ value = 0;}
        else {break;}
        printf("Invalid input !!! Please try again.\n");
    }

    search->day = day;
    search->month = month;
}

void loop()
{
    struct Date Doomsday, search;
    
    read_date(&search);
    printf("%d %d", search.day, search.month);

    //Doomsday.wday = (3 + ((x-2000) + (x-2000) / 4) % 7) % 7;
    //change_to_wday(Doomsday.wday);
}
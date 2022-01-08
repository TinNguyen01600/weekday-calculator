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

void loop()
{
    struct Date Doomsday, search;
    int x;
    scanf("%d", &x);

    Doomsday.wday = (3 + ((x-2000) + (x-2000) / 4) % 7) % 7;
    change_to_wday(Doomsday.wday);
}
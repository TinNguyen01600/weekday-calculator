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

bool check_month_31(int month){
  int month_31[7] = {1, 3, 5, 7, 8, 10, 12};
  for (int i = 0; i<7; i++){
    if (month == month_31[i]){ return true; break;}
  }
  return false;
}

bool check_month_30(int month){
  int month_30[4] = {4, 6, 9, 11};
  for (int i = 0; i<4; i++){
    if (month == month_30[i]){ return true; break;}
  }
  return false;
}

bool leap_year(int year){
  if(year % 100 == 0 && year % 400 == 0){return true;}
  else if(year % 4 == 0){return true;}
  else return false;
}

bool check_valid_date(int day, int month, int year){
  int value = 0;
  if (day > 0 && month > 0 && year > 0){ value++; }
  if (check_month_31(month) && day <= 31){ value++; }
  else if(check_month_30(month) && day <= 30){ value++; }
  else if (month == 2){
    if(leap_year(year) && day <= 29){ value++; }
    else if(day <= 28){ value++; }
  }


  if (value == 2) return true;
  else return false;
}

void read_date(struct Date *search){
    char c1,c2, c3;
    int day, month, year;
    int value = 0;
    char input[100];
    while (value == 0)
    {
        printf("Enter a date (format dd/mm/yyyy or dd.mm.yyyy): ");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%d%c%d%c%d%c", &day, &c1, &month, &c2, &year, &c3);

        if((c1 == '.' && c2 == '.') || (c1 == '/' && c2 == '/')){ value++;}
        if((int)c3 == 10 ){ value++;}   //ensure that there is no more symbol or number after year (Enter is pressed)

        if (check_valid_date(day, month, year) && value == 2){ break;}      
        else {
          value = 0;
          printf("Invalid input !!! Please try again.\n");
        }     
    }
    search->day = day;
    search->month = month;
    search->year = year;
}

struct Date * calculate_wday(struct Date *search, struct Date *Doomsday)
{
  Doomsday->year = search->year;
    if(Doomsday->year < 2000){
      Doomsday->wday = (3 - ((2000-Doomsday->year) + (2000-Doomsday->year) / 7) % 7) % 7;
    }
    else {
      Doomsday->wday = (3 + ((Doomsday->year-2000) + (Doomsday->year-2000) / 4) % 7) % 7;
    }
  

  return Doomsday;
}

void loop()
{
    struct Date Doomsday, search;
    
    read_date(&search);
    //printf("%d %d %d", search.day, search.month, search.year);

    calculate_wday(&search, &Doomsday);
    
    change_to_wday(Doomsday.wday);
}
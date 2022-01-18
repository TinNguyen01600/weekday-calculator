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
  if(Doomsday->year >= 2000){
    Doomsday->wday = (3 + ((Doomsday->year-2000) + (Doomsday->year-2000) / 4) % 7) % 7;
  }
  else {
    Doomsday->wday = (2 - ((2000-Doomsday->year) + (2000-Doomsday->year) / 4) % 7) % 7;
  }
  
  switch ((*search).month)
  {
  case Jan:
    if(leap_year((*search).year)) (*Doomsday).day = 4;
    else  (*Doomsday).day = 3;
    break;
  
  case Feb:
    if(leap_year((*search).year)) (*Doomsday).day = 29;
    else  (*Doomsday).day = 28;
    break;

  case Mar:
    (*Doomsday).day = 14;
    break;

  case April:
    (*Doomsday).day = 4;
    break;

  case May:
    (*Doomsday).day = 9;
    break;

  case Jun:
    (*Doomsday).day = 6;
    break;

  case Jul:
    (*Doomsday).day = 11;
    break;

  case Aug:
    (*Doomsday).day = 8;
    break;

  case Sep:
    (*Doomsday).day = 5;
    break;

  case Oct:
    (*Doomsday).day = 10;
    break;

  case Nov:
    (*Doomsday).day = 7;
    break;

  case Dec:
    (*Doomsday).day = 12;
    break;

  default:
    break;
  }

  int k = (*search).day - (*Doomsday).day + 14;     //k is the number of days difference between the search date and doomsday.

  (*search).wday = ((*Doomsday).wday + k) % 7;
  return search;
}

void keyboard_hit()
{
    system("cls");
    int ch;
    printf("Press ENTER to start\n");
    printf("Press ESC to exit\n");
    while(1){
        if ( kbhit() ) {
            // Stores the pressed key in ch
            ch = getch();
            // when escape is pressed
            if ((int)ch == 27)
                exit(0);
            // when enter is pressed
            if ((int)ch == 13)
                break;
        }
    }
}

void loop()
{
    keyboard_hit();

    struct Date Doomsday, search;
    
    read_date(&search);
    calculate_wday(&search, &Doomsday);
    change_to_wday(search.wday);

    Sleep(1000);
    loop();
}
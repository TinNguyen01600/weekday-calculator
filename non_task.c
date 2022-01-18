//This file contains all the non-task functions necessary for the program
#include "mylib.h"

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
#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

enum week{Sun = 1, Mon, Tue, Wed, Thu, Fri, Sat}; //macro definition for weekdays
enum month {Jan = 1, Feb, Mar, April, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};      //macro definition for months

struct Date {
    int wday;
    int day;
    int month;
    int year;
};

void change_to_wday(int n);     // This function change the weekday number calculated (0,1,2,...) into weekday name (Sunday, Monday, Tuesday, ...)
void loop();                     // This function is the backbone of the program, which repeats itself until user exits
void read_date(struct Date *);               // This function is used to read the date input from user's keyboard and store it to a variable
bool check_valid_date(int, int, int);       //check if the date entered is valid
bool check_month_31(int);                 //This function is used to check if the month entered has 31 days to ensure that the day entered is valid.
bool check_month_30(int);                   //same as check_month_31() but for 30-days months
bool leap_year(int);                        //check if the entered year is leap year
struct Date * calculate_wday(struct Date *, struct Date *);     //calculate the weekday, receives 2 parameter: entered date and doomsday
#include <stdio.h>
#include <windows.h>

enum week{Sun = 1, Mon, Tue, Wed, Thu, Fri, Sat}; //macro definition

struct Date {
    int wday;
    int day;
    int month;
    int year;
};

void change_to_wday(int n);     // This function change the weekday number calculated (0,1,2,...) into weekday name (Sunday, Monday, Tuesday, ...)
void loop();                     // This function is the backbone of the program, which repeats itself until user exits
void read_date(struct Date *);               // This function is used to read the date input from user's keyboard and store it to a variable
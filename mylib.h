#include <stdio.h>
#include <windows.h>

enum week{Sun = 1, Mon, Tue, Wed, Thu, Fri, Sat}; //macro definition

struct Date {
    int wday;
    int day;
    int month;
    int year;
};

void change_to_wday(int n);
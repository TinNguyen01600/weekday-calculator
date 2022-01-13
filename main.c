#include "mylib.h"

int main(void)
{
    //a useful fact that 2000's doomsday is Tuesday.
    struct Date Doomsday2000;
    Doomsday2000.wday = 3;

    printf("This application calculates the weekday of any day ");
    printf("\nthroughout the history, or even in the far, far future. \n\n");

    loop();
}
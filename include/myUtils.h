#ifndef INCLUDE_MYUTILS_H
#define INCLUDE_MYUTILS_H

#include <stdio.h>
#include <iostream>
using namespace std;


    char* myAsctime (const struct tm *timeptr) {
        
        static char result[26];

        sprintf(result, "%d-%.2d-%.2d %.2d:%.2d:%.2d",
        1900 + timeptr->tm_year, timeptr->tm_mon, timeptr->tm_mday,
        timeptr->tm_hour, timeptr->tm_min, timeptr->tm_sec);
        return result;
    }

#endif

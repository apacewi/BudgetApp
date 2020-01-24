#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <windows.h>
#include <winbase.h>
#include "AuxiliaryMethods.h"

using namespace std;

class Date
{
    int day, month, year;
    AuxiliaryMethods auxiliaryMethods;
public:

   bool checkCorrectnessOfDate(string date);
   Date getCurrentDayDate();
   Date getDateWithPastMonth();
   Date changeToDateObject(string dateTobeChecked);
   int checkDaysOfChoosenMonth(Date choosenDate);
   string getDateInString(Date dateToString);
   int changeDateToInt(Date dateToChange);
   string convertToTrueDateFormat(int dateInInt, int month);
   int convertTrueDateToInt(string trueDate);
   int getDay();
   int getMonth();
   int getYear();
   void setDay(int newDay);
   void setMonth(int newMonth);
};

#endif

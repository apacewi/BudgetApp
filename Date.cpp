#include "Date.h"

bool Date::checkCorrectnessOfDate(string date){

    Date choosenDate;
    string choosenDateDayInString = "",choosenDateMonthInString =  "", choosenDateYearInString = "";

    for (int i = 0; i < date.length(); i++){

        if (i > 7)
            choosenDateDayInString += date[i];

        if(i > 4 && i < 7)
            choosenDateMonthInString += date[i];

        if (i < 4)
            choosenDateYearInString += date[i];
    }
    choosenDate.day = auxiliaryMethods.convertStringToInt(choosenDateDayInString);
    choosenDate.month = auxiliaryMethods.convertStringToInt(choosenDateMonthInString);
    choosenDate.year = auxiliaryMethods.convertStringToInt(choosenDateYearInString);

    if (choosenDate.day > 0 && choosenDate.day <= checkDaysOfChoosenMonth(choosenDate) && choosenDate.year >= 2000 && choosenDate.month <13 && choosenDate.month > 0)
        return true;
    else
        return false;


}
int Date::checkDaysOfChoosenMonth(Date choosenDate){

    int numberOfCurrentMonthDays;

    if ((choosenDate.month == 4) || (choosenDate.month == 6) || (choosenDate.month == 9) || (choosenDate.month == 11)) {
        numberOfCurrentMonthDays = 30;
    } else if(choosenDate.month == 2) {
        if((choosenDate.year % 4 ==0) && (choosenDate.year % 100 !=0) || (choosenDate.year % 400 ==0))  {
            numberOfCurrentMonthDays = 29;
        } else {
            numberOfCurrentMonthDays = 28;
        }
    } else {
        numberOfCurrentMonthDays = 31;
    }
    return numberOfCurrentMonthDays;
}
Date Date::getCurrentDayDate(){

    Date currentDayDate;
    SYSTEMTIME st;
    GetSystemTime(&st);
    currentDayDate.year = st.wYear;
    currentDayDate.month = st.wMonth;
    currentDayDate.day = st.wDay;

    return currentDayDate;
}
Date Date::getDateWithPastMonth(){

    Date dateWithPastMonth;
    SYSTEMTIME st;
    GetSystemTime(&st);
    dateWithPastMonth.year = st.wYear;
    dateWithPastMonth.month = st.wMonth;
    dateWithPastMonth.day = st.wDay;

    if (dateWithPastMonth.month == 1 ){
        dateWithPastMonth.month = 12;
        dateWithPastMonth.year = dateWithPastMonth.year - 1;
    }
    else
        dateWithPastMonth.month = dateWithPastMonth.month - 1;

    return dateWithPastMonth;
}
Date Date::changeToDateObject(string dateTobeChecked){

    Date choosenDate;
    string choosenDateDayInString = "",choosenDateMonthInString =  "", choosenDateYearInString = "";
    for (int i = 0; i < dateTobeChecked.length(); i++){

        if (i > 7)
            choosenDateDayInString += dateTobeChecked[i];

        if(i > 4 && i < 7)
            choosenDateMonthInString += dateTobeChecked[i];

        if (i < 4)
            choosenDateYearInString += dateTobeChecked[i];
    }
    choosenDate.day = auxiliaryMethods.convertStringToInt(choosenDateDayInString);
    choosenDate.month = auxiliaryMethods.convertStringToInt(choosenDateMonthInString);
    choosenDate.year = auxiliaryMethods.convertStringToInt(choosenDateYearInString);
    return choosenDate;
}
string Date::getDateInString(Date dateToString){

    string dateDay, dateMonth, dateYear;

    dateDay = auxiliaryMethods.convertIntToString(dateToString.day);
    dateMonth = auxiliaryMethods.convertIntToString(dateToString.month);
    dateYear = auxiliaryMethods.convertIntToString(dateToString.year);

    string stringDate = dateYear;
    stringDate += dateMonth;
    stringDate += dateDay;

    return stringDate;
}
string Date::convertToTrueDateFormat(int dateInInt, int month) {

    string stringDate, dateToSave = "", correctedDateToSave = "";

    stringDate = auxiliaryMethods.convertIntToString(dateInInt);

    if (stringDate.length() == 6) {
        for(int i = 0; i < stringDate.length(); i++) {
            dateToSave += stringDate[i];
            if (i == 3 || i == 4){
                dateToSave += '-';
                dateToSave += '0';
            }
        }
        return dateToSave;
    }
    else if ((stringDate.length() == 7 && stringDate[5] != '0' && stringDate[4] != '0' && month < 10) || (stringDate.length() == 7 && stringDate[5] == '0' && stringDate[4] != '0')) {
        for(int i = 0; i < stringDate.length(); i++) {
            dateToSave += stringDate[i];
            if (i == 3 ){
                dateToSave += '-';
                dateToSave += '0';
            }
            if (i == 4 ){
                dateToSave += '-';
            }
        }
        return dateToSave;
    }
    else if (stringDate.length() == 7 && stringDate[4] == '0'&& stringDate[6] != '0') {
        for(int i = 0; i < stringDate.length(); i++) {
            dateToSave += stringDate[i];
            if (i == 3 ){
                dateToSave += '-';
            }
            if (i == 5 ){
                dateToSave += '-';
                dateToSave += '0';
            }
        }
        return dateToSave;
    }
    else if ((stringDate.length() == 8 && stringDate[4] == '0' && stringDate[6] != '0') || (stringDate.length() == 8 && stringDate[4] == '0' && stringDate[6] == '0') || (stringDate.length() == 8 && stringDate[4] != '0' && stringDate[6] == '0') ) {
        for(int i = 0; i < stringDate.length(); i++) {
            dateToSave += stringDate[i];
            if (i == 3 || i == 5){
                dateToSave += '-';
            }
        }
        return dateToSave;
    }
    else if (stringDate.length() == 7 && stringDate[6] != '0'&& stringDate[4] != '0' && month >= 10) {
        for(int i = 0; i < stringDate.length(); i++) {
            dateToSave += stringDate[i];
            if (i == 3 ){
                dateToSave += '-';
            }
            if (i == 5 ){
                dateToSave += '-';
                dateToSave += '0';
            }
        }
        return dateToSave;
    }
    else{
            for(int i = 0; i < stringDate.length(); i++) {
            dateToSave += stringDate[i];
            if (i == 3 || i == 5){
                dateToSave += '-';
            }
        }
        return dateToSave;
    }

}
int Date::convertTrueDateToInt(string trueDate){
    string stringDate = "";
    for (int i = 0; i < trueDate.length(); i++){
        if (trueDate[i] == '-'){}
        else
        stringDate += trueDate[i];
    }
    return auxiliaryMethods.convertStringToInt(stringDate);
}
int Date::changeDateToInt(Date dateToChange){
    return auxiliaryMethods.convertStringToInt(getDateInString(dateToChange));
}
int Date::getDay(){
    return day;
}
int Date::getMonth(){
    return month;
}
int Date::getYear(){
    return year;
}
void Date::setDay(int newDay){
    day = newDay;
}
void Date::setMonth(int newMonth){
    month = newMonth;
}

#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <cstdlib>

using namespace std;

class AuxiliaryMethods
{
public:
    string loadLine();
    string convertIntToString(int number);
    int convertStringToInt(string number);
    string idWithNumber(int number);
    int changeIdToInteger(string idWithNumber);
    char loadChar();
    float convertToFloat(string amount);
    string convertFloatToString(float number);
    string changeCommaToDot(string word);
};

#endif

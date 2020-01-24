#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>

using namespace std;

class Operations
{
protected:
    int operationId, userId, date;
    string item;
    float amount;
public:
    int getOperationId();
    int getUserId();
    int getDate();
    string getItem();
    float getAmount();
    int setOperationId(int newOperationId);
    int setUserId(int newUserId);
    int setDate(int newDate);
    string setItem(string newNameOfItem);
    float setAmount(float newAmount);
};

#endif

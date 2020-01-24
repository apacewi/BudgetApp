#include "operation.h"

int Operations::getOperationId()
{
    return operationId;
}
int Operations::getUserId(){
    return userId;
}
int Operations::getDate(){
    return date;
}
string Operations::getItem(){
    return item;
}
float Operations::getAmount(){
    return amount;
}
int Operations::setOperationId(int newOperationId)
{
    operationId = newOperationId;
}
int Operations::setUserId(int newUserId){

    userId = newUserId;
}
int Operations::setDate(int newDate){
    date = newDate;
}
string Operations::setItem(string newNameOfItem){
    item = newNameOfItem;
}
float Operations::setAmount(float newAmount){
    amount = newAmount;
}

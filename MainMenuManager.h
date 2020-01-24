#ifndef MAINMENUMANAGER_H
#define MAINMENUMANAGER_H

#include <iostream>
#include <vector>
#include <iomanip>
#include "AuxiliaryMethods.h"
#include "Date.h"
#include "IncomesFile.h"
#include "Income.h"
#include "Expanse.h"
#include "ExpansesFile.h"

using namespace std;

class MainMenuManager
{
    const int LOGED_USER_ID;
    string kindOfOperation, correctedOperationAmount;
    vector <Income> incomes;
    vector <Expanse> expanses;
    IncomesFile incomesFile;
    ExpansesFile expansesFile;
    AuxiliaryMethods auxiliaryMethods;
    Date date, operationDate;

    void displayOperationAddMenu();
    vector <Income> sortIncomesVector(vector <Income> &sortedIncomes, int left, int right);
    vector <Expanse> sortExpansesVector(vector <Expanse> &choosenExpanses, int left, int right);
    void displayBalance(vector <Income> &sortedIncomes, vector <Expanse> &sortedExpanses);
public:
    MainMenuManager(int logedUserId, string incomesFileName, string expansesFileName) : LOGED_USER_ID(logedUserId), incomesFile(incomesFileName), expansesFile(expansesFileName) {
        incomes = incomesFile.getIncomesVector();
        expanses = expansesFile.getExpansesVector();
    };
    void addIncome();
    void addExpanse();
    void displayCurrentMonthBalance();
    void displayLastMonthBalance();
    void displaySelectedTimeBalance();
    char displayMainMenu();
};

#endif

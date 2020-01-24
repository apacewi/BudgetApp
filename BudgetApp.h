#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include <iostream>
#include "UserManager.h"
#include "MainMenuManager.h"

using namespace std;

class BudgetApp
{
    int logedUserId;
    const string INCOMES_FILE_NAME, EXPANSES_FILE_NAME;
    UserManager userManager;
    MainMenuManager *mainMenu;

public:
    BudgetApp (string usersFileName, string incomesFile, string expansesFile) : userManager(usersFileName), INCOMES_FILE_NAME(incomesFile), EXPANSES_FILE_NAME(expansesFile) {
    logedUserId = 0;
    };
    ~BudgetApp() {logedUserId = 0;}
    void loginUser();
    void registerUser();
    void addIncome();
    void addExpense();
    int getUserId();
    char displayMainMenu();
    char displayLoginMenu();
    void displayCurrentMonthBalance();
    void displayLastMonthBalance();
    void displaySelectedTimeBalance();
    void changePassword();
    void logout();
    void tes();
};

#endif

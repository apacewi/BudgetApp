#include "BudgetApp.h"

void BudgetApp::loginUser()
{
    logedUserId = userManager.loginUser();
    if (logedUserId == 0)
    {
        cout << "Wrong Login or Password! " << endl;
        system("Pause");
    }
    else{
        mainMenu = new MainMenuManager(logedUserId, INCOMES_FILE_NAME, EXPANSES_FILE_NAME);
    }
}
void BudgetApp::registerUser()
{
    userManager.registerUser();
}
void BudgetApp::tes(){
    cout << logedUserId;
}
void BudgetApp::addIncome(){
    mainMenu -> addIncome();
}
void BudgetApp::addExpense(){
    mainMenu -> addExpanse();
}
void BudgetApp::logout(){
    delete mainMenu;
    logedUserId = 0;
}
void BudgetApp::displayCurrentMonthBalance(){
    mainMenu -> displayCurrentMonthBalance();
}
void BudgetApp::displayLastMonthBalance(){
    mainMenu -> displayLastMonthBalance();
}
void BudgetApp::displaySelectedTimeBalance(){
    mainMenu -> displaySelectedTimeBalance();
}
char BudgetApp::displayLoginMenu(){
    char choice;
    AuxiliaryMethods *auxiliaryMethods = new AuxiliaryMethods;

    system("cls");
    cout << "    >>> Login/Registration Menu <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Login" << endl;
    cout << "9. Close program" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = auxiliaryMethods -> loadChar();

    delete auxiliaryMethods;

    return choice;
}
int BudgetApp::getUserId(){
    return  logedUserId;
}
char BudgetApp::displayMainMenu(){
   char choice = mainMenu -> displayMainMenu();
   return choice;
}
void BudgetApp::changePassword(){
    userManager.changePassword();
}

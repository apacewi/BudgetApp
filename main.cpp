#include <iostream>
#include "BudgetApp.h"

using namespace std;

int main() {

    char choice;
    BudgetApp budgetApp("users.xml", "incomes.xml", "expanses.xml");

    while (true) {
        if(budgetApp.getUserId() == 0) {
            choice = budgetApp.displayLoginMenu();
            if (choice == '1') {
                budgetApp.registerUser();
            } else if (choice == '2') {
                budgetApp.loginUser();
            } else if (choice == '9') {
                exit(0);
            }
        } else if (budgetApp.getUserId() > 0) {
            choice = budgetApp.displayMainMenu();
            if (choice == '1') {
                budgetApp.addIncome();
            }
            if (choice == '2') {
                budgetApp.addExpense();
            }
            if (choice == '3') {
                budgetApp.displayCurrentMonthBalance();
            }
            if (choice == '4') {
                budgetApp.displayLastMonthBalance();
            }
            if (choice == '5') {
                budgetApp.displaySelectedTimeBalance();
            }
            if (choice == '6') {
               budgetApp.changePassword();
            }
            if (choice == '7') {
               budgetApp.logout();
            }
        }
    }
    return 0;
}

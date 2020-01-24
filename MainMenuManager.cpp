#include "MainMenuManager.h"

void MainMenuManager::displayOperationAddMenu()
{
    char choice;
    string amountOfOperation, dateToCheck;
    system("cls");
    cout << "Is it from today? " << endl
         << "1. Yes" << endl
         << "2. No" << endl;
    choice = auxiliaryMethods.loadChar();
    while (true){
    if (choice == '1'){
      operationDate = date.getCurrentDayDate();
        break;
    }
    else if (choice == '2'){
        cout << "Please give date in yyyy-mm-dd. (Example: 2017-11-23) ";
        dateToCheck = auxiliaryMethods.loadLine();
        if (date.checkCorrectnessOfDate(dateToCheck)){
            operationDate = date.changeToDateObject(dateToCheck);
            break;
        }
        else
            cout << "Wrong format of date, try again. ";
    }
    else {
        cout << "Wrong choice, try again. ";
        choice = auxiliaryMethods.loadChar();
    }
    }
    cout << "What kind of operation it is? " << endl;
        kindOfOperation = auxiliaryMethods.loadLine();

    cout << "Amount? " << endl;
        amountOfOperation = auxiliaryMethods.loadLine();
        correctedOperationAmount = auxiliaryMethods.changeCommaToDot(amountOfOperation);
}
void MainMenuManager::addIncome(){

    Income income;

    displayOperationAddMenu();

    income.setUserId(LOGED_USER_ID);
    income.setDate(date.changeDateToInt(operationDate));
    income.setItem(kindOfOperation);
    income.setAmount(auxiliaryMethods.convertToFloat(correctedOperationAmount));
    income.setOperationId(0);

    incomesFile.addIncome(income, operationDate.getMonth());
    system("cls");
    cout << "Income succesfully added! " << endl;
    system("Pause");
}
void MainMenuManager::addExpanse(){

    Expanse expanse;

    displayOperationAddMenu();

    expanse.setUserId(LOGED_USER_ID);
    expanse.setDate(date.changeDateToInt(operationDate));
    expanse.setItem(kindOfOperation);
    expanse.setAmount(auxiliaryMethods.convertToFloat(correctedOperationAmount));
    expanse.setOperationId(0);

    expansesFile.addExpanse(expanse, operationDate.getMonth());
    system("cls");
    cout << "Expanse succesfully added! " << endl;
    system("Pause");
    }
vector <Income> MainMenuManager::sortIncomesVector(vector <Income> &sortedIncomes, int left, int right){

    Income auxiliaryIncome;
    int i = left;
    int j = right;
    int x = sortedIncomes[( left + right ) / 2 ].getDate();

    do
    {
        while( sortedIncomes[ i ].getDate() < x )
             i++;

        while( sortedIncomes[ j ].getDate() > x )
             j--;

        if( i <= j )
        {
            auxiliaryIncome = sortedIncomes[i];
            sortedIncomes[i] = sortedIncomes[j];
            sortedIncomes[j] = auxiliaryIncome;

            i++;
            j--;
        }
    } while( i <= j );

    if( left < j ) sortIncomesVector(sortedIncomes, left, j );

    if( right > i ) sortIncomesVector(sortedIncomes, i, right );

    return sortedIncomes;
}
vector <Expanse> MainMenuManager::sortExpansesVector(vector <Expanse> &sortedExpanses, int left, int right){

    Expanse auxiliaryExpanse;
    int i = left;
    int j = right;
    int x = sortedExpanses[( left + right ) / 2 ].getDate();

    do
    {
        while( sortedExpanses[ i ].getDate() < x )
             i++;

        while( sortedExpanses[ j ].getDate() > x )
             j--;

        if( i <= j )
        {
            auxiliaryExpanse = sortedExpanses[i];
            sortedExpanses[i] = sortedExpanses[j];
            sortedExpanses[j] = auxiliaryExpanse;

            i++;
            j--;
        }
    } while( i <= j );

    if( left < j ) sortExpansesVector(sortedExpanses, left, j );

    if( right > i ) sortExpansesVector(sortedExpanses, i, right );

    return sortedExpanses;
}

void MainMenuManager::displayCurrentMonthBalance(){

    int currentDateInInt, secondDateInInt;
    Date firstChoosenDate, secondChoosenDate;
    vector <Income> choosenIncomes, sortedIncomes;
    vector <Expanse> choosenExpanses, sortedExpanses;
    secondChoosenDate = date.getCurrentDayDate();
    firstChoosenDate = secondChoosenDate;
    firstChoosenDate.setDay(1);

    currentDateInInt = date.convertTrueDateToInt(date.convertToTrueDateFormat(date.changeDateToInt(secondChoosenDate), secondChoosenDate.getMonth()));
    secondDateInInt = date.convertTrueDateToInt(date.convertToTrueDateFormat(date.changeDateToInt(firstChoosenDate), firstChoosenDate.getMonth()));

    choosenIncomes = incomesFile.loadIncomesFromChoosenTime(LOGED_USER_ID, currentDateInInt, secondDateInInt);
    choosenExpanses = expansesFile.loadExpansesFromChoosenTime(LOGED_USER_ID, currentDateInInt, secondDateInInt);

    if (choosenIncomes.size() == 0 && choosenExpanses.size() == 0){
        cout << "No data found. " << endl;
    }
    else{
            if (choosenIncomes.size() != 0)
    sortedIncomes = sortIncomesVector(choosenIncomes, 0, choosenIncomes.size()-1);
            if (choosenExpanses.size() != 0)
    sortedExpanses = sortExpansesVector(choosenExpanses, 0, choosenExpanses.size()-1);

    displayBalance(sortedIncomes, sortedExpanses);

     choosenIncomes.clear();
     sortedIncomes.clear();
     choosenExpanses.clear();
     sortedIncomes.clear();
    }
    system("Pause");
}
void MainMenuManager::displayLastMonthBalance(){

    int currentDateInInt, secondDateInInt, pastMonthDays;
    Date firstChoosenDate, secondChoosenDate;
    vector <Income> choosenIncomes, sortedIncomes;
    vector <Expanse> choosenExpanses, sortedExpanses;

    secondChoosenDate = date.getDateWithPastMonth();
    pastMonthDays = date.checkDaysOfChoosenMonth(secondChoosenDate);
    secondChoosenDate.setDay(pastMonthDays);
    firstChoosenDate = secondChoosenDate;
    firstChoosenDate.setDay(1);

    currentDateInInt = date.convertTrueDateToInt(date.convertToTrueDateFormat(date.changeDateToInt(secondChoosenDate), secondChoosenDate.getMonth()-1));
    secondDateInInt = date.convertTrueDateToInt(date.convertToTrueDateFormat(date.changeDateToInt(firstChoosenDate), firstChoosenDate.getMonth()));

    choosenIncomes = incomesFile.loadIncomesFromChoosenTime(LOGED_USER_ID, currentDateInInt, secondDateInInt);
    choosenExpanses = expansesFile.loadExpansesFromChoosenTime(LOGED_USER_ID, currentDateInInt, secondDateInInt);

    if (choosenIncomes.size() == 0 && choosenExpanses.size() == 0){
        cout << "No data found. " << endl;
    }
    else{
            if (choosenIncomes.size() != 0)
    sortedIncomes = sortIncomesVector(choosenIncomes, 0, choosenIncomes.size()-1);
            if (choosenExpanses.size() != 0)
    sortedExpanses = sortExpansesVector(choosenExpanses, 0, choosenExpanses.size()-1);

    displayBalance(sortedIncomes, sortedExpanses);

     choosenIncomes.clear();
     sortedIncomes.clear();
     choosenExpanses.clear();
     sortedIncomes.clear();
    }
    system("Pause");
}
void MainMenuManager::displaySelectedTimeBalance(){

    int currentDateInInt, secondDateInInt, pastMonthDays;
    Date firstChoosenDate, secondChoosenDate;
    string startDay, endDay;
    vector <Income> choosenIncomes, sortedIncomes;
    vector <Expanse> choosenExpanses, sortedExpanses;

    do{
    cout << "Date you want to start (yyyy-mm-dd): ";
    startDay = auxiliaryMethods.loadLine();
    if (date.checkCorrectnessOfDate(startDay) != true){
        cout << "Wrong data, try again. ";
    }
    }while (date.checkCorrectnessOfDate(startDay) != true);

    do{
    cout << endl << "Date you want to end (yyyy-mm-dd): ";
    endDay = auxiliaryMethods.loadLine();
    if (date.checkCorrectnessOfDate(endDay) != true){
        cout << "Wrong data, try again. ";
    }
    }while (date.checkCorrectnessOfDate(endDay) != true);

    secondChoosenDate = date.changeToDateObject(endDay);
    firstChoosenDate = date.changeToDateObject(startDay);

    currentDateInInt = date.convertTrueDateToInt(date.convertToTrueDateFormat(date.changeDateToInt(secondChoosenDate), secondChoosenDate.getMonth()-1));
    secondDateInInt = date.convertTrueDateToInt(date.convertToTrueDateFormat(date.changeDateToInt(firstChoosenDate), firstChoosenDate.getMonth()));

    choosenIncomes = incomesFile.loadIncomesFromChoosenTime(LOGED_USER_ID, currentDateInInt, secondDateInInt);
    choosenExpanses = expansesFile.loadExpansesFromChoosenTime(LOGED_USER_ID, currentDateInInt, secondDateInInt);

    if (choosenIncomes.size() == 0 && choosenExpanses.size() == 0){
        cout << "No data found. " << endl;
    }
    else{
            if (choosenIncomes.size() != 0)
    sortedIncomes = sortIncomesVector(choosenIncomes, 0, choosenIncomes.size()-1);
            if (choosenExpanses.size() != 0)
    sortedExpanses = sortExpansesVector(choosenExpanses, 0, choosenExpanses.size()-1);

    displayBalance(sortedIncomes, sortedExpanses);

     choosenIncomes.clear();
     sortedIncomes.clear();
     choosenExpanses.clear();
     sortedIncomes.clear();
    }
    system("Pause");
}

void MainMenuManager::displayBalance(vector <Income> &sortedIncomes, vector <Expanse> &sortedExpanses){

    float totalIncomes = 0 , totalExpanses = 0;

    for (int i = 0; i < sortedExpanses.size(); i++){
        cout << endl << "Expanse ID: " << sortedExpanses[i].getOperationId() << endl;
        cout << "User ID: " << sortedExpanses[i].getUserId() << endl;
        cout << "Date: " << sortedExpanses[i].getDate() << endl;
        cout << "Item: " << sortedExpanses[i].getItem() << endl;
        cout << "Amount: " << fixed << setprecision(2) << sortedExpanses[i].getAmount() << endl;
          totalExpanses += sortedExpanses[i].getAmount();
    }

    for (int i = 0; i < sortedIncomes.size(); i++){
        cout << endl << "Income ID: " << sortedIncomes[i].getOperationId() << endl;
        cout << "User ID: " << sortedIncomes[i].getUserId() << endl;
        cout << "Date: " << sortedIncomes[i].getDate() << endl;
        cout << "Item: " << sortedIncomes[i].getItem() << endl;
        cout << "Amount: " << fixed << setprecision(2) << sortedIncomes[i].getAmount() << endl;
          totalIncomes += sortedIncomes[i].getAmount();
    }
    cout << endl << "All expanses: " << fixed << setprecision(2) << totalExpanses << endl;
    cout << "All incomes: " << fixed << setprecision(2) << totalIncomes << endl;

    if (totalIncomes - totalExpanses > 0)
        cout << "Great, you are " << totalIncomes - totalExpanses << " ahead! " << endl;
    else if(totalIncomes - totalExpanses == 0)
        cout << "Not bad - not good,  you have 0 difference. " << endl;
    else if (totalIncomes - totalExpanses < 0)
        cout << "Not good, you need to save more money! You have " <<  totalIncomes - totalExpanses << " difference back." << endl;

}
char MainMenuManager::displayMainMenu(){

    char choice;

    system("cls");
    cout << "    >>> MAIN  MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add Income." << endl;
    cout << "2. Add Expanse." << endl;
    cout << "3. Display Current Month Balance" << endl;
    cout << "4. Display Last Month Balance" << endl;
    cout << "5. Display Selected Time Balance" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Logout" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = auxiliaryMethods.loadChar();
    return choice;
}

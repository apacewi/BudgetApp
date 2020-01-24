#include "IncomesFile.h"

void IncomesFile::addIncome(Income newIncome, int month){

    if (xml.Load(NAME_OF_XML_FILE) == true) {

        xml.FindElem("IncomesFile");
        xml.IntoElem();
        xml.AddElem(auxiliaryMethods.idWithNumber(incomes[incomes.size()-1].getOperationId()+1));
        xml.IntoElem();
        xml.AddElem("UserID", auxiliaryMethods.idWithNumber(newIncome.getUserId()));
        xml.AddElem("Date", date.convertToTrueDateFormat(newIncome.getDate(), month));
        xml.AddElem("Item", newIncome.getItem());
        xml.AddElem("Amount", auxiliaryMethods.convertFloatToString(newIncome.getAmount()));
        xml.Save(NAME_OF_XML_FILE);
    }
    else {
        xml.AddElem("IncomesFile");
        xml.IntoElem();
        xml.AddElem("ID1");
        xml.IntoElem();
        xml.AddElem("UserID", auxiliaryMethods.idWithNumber(newIncome.getUserId()));
        xml.AddElem("Date", date.convertToTrueDateFormat(newIncome.getDate(), month));
        xml.AddElem("Item", newIncome.getItem());
        xml.AddElem("Amount", auxiliaryMethods.convertFloatToString(newIncome.getAmount()));
        xml.Save(NAME_OF_XML_FILE);
    }
    loadIncomes();
}
void IncomesFile::loadIncomes() {

    Income income;

    if (xml.Load(NAME_OF_XML_FILE) == true) {
        xml.ResetMainPos();
        xml.FindElem("IncomesFile");
        xml.IntoElem();

        while (xml.FindElem() == true) {

            income.setOperationId(auxiliaryMethods.changeIdToInteger(xml.GetTagName()));

            xml.FindChildElem("UserID");
            income.setUserId(auxiliaryMethods.changeIdToInteger(xml.GetChildData()));

            xml.FindChildElem("Date");
            income.setDate(date.convertTrueDateToInt(xml.GetChildData()));

            xml.FindChildElem("Item");
            income.setItem(xml.GetChildData());

            xml.FindChildElem("Amount");
            income.setAmount(auxiliaryMethods.convertToFloat(xml.GetChildData()));

            incomes.push_back(income);
        }
    }
    else {
        cout << "Incomes file does not exist! " << endl;
    }
}
vector <Income> IncomesFile::getIncomesVector(){
    return incomes;
}
vector <Income> IncomesFile::loadIncomesFromChoosenTime(int logedUserId,int secondChoosenDate,int firstChoosenDate) {

    Income choosenIncome;
    vector <Income> choosenIncomes;

    if (xml.Load(NAME_OF_XML_FILE) == true) {
        xml.ResetPos();
        xml.FindElem("IncomesFile");
        xml.IntoElem();

        do {

            choosenIncome.setOperationId(auxiliaryMethods.changeIdToInteger(xml.GetTagName()));

            xml.FindChildElem("UserID");
            choosenIncome.setUserId(0);
            if (auxiliaryMethods.changeIdToInteger(xml.GetChildData()) == logedUserId) {
                choosenIncome.setUserId(auxiliaryMethods.changeIdToInteger(xml.GetChildData()));

                xml.FindChildElem("Date");
                choosenIncome.setDate(0);
                if(date.convertTrueDateToInt(xml.GetChildData()) >= firstChoosenDate && date.convertTrueDateToInt(xml.GetChildData()) <= secondChoosenDate) {
                    choosenIncome.setDate(date.convertTrueDateToInt(xml.GetChildData()));

            xml.FindChildElem("Item");
            choosenIncome.setItem(xml.GetChildData());

            xml.FindChildElem("Amount");
            choosenIncome.setAmount(auxiliaryMethods.convertToFloat(xml.GetChildData()));
                }
            }

            if (choosenIncome.getUserId() != 0 && choosenIncome.getDate() != 0){
                choosenIncome.getItem();
                choosenIncomes.push_back(choosenIncome);
            }
        } while (xml.FindElem() == true);
    }
    else {
        cout << "No data. " << endl;
    }
    return choosenIncomes;
}

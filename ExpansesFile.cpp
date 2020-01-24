#include "ExpansesFile.h"

void ExpansesFile::addExpanse(Expanse newExpanse, int month){

    if (xml.Load(NAME_OF_XML_FILE) == true) {

        xml.FindElem("ExpansesFile");
        xml.IntoElem();
        xml.AddElem(auxiliaryMethods.idWithNumber(expanses[expanses.size()-1].getOperationId()+1));
        xml.IntoElem();
        xml.AddElem("UserID", auxiliaryMethods.idWithNumber(newExpanse.getUserId()));
        xml.AddElem("Date", date.convertToTrueDateFormat(newExpanse.getDate(), month));
        xml.AddElem("Item", newExpanse.getItem());
        xml.AddElem("Amount", auxiliaryMethods.convertFloatToString(newExpanse.getAmount()));
        xml.Save(NAME_OF_XML_FILE);
    }
    else {
        xml.AddElem("ExpansesFile");
        xml.IntoElem();
        xml.AddElem("ID1");
        xml.IntoElem();
        xml.AddElem("UserID", auxiliaryMethods.idWithNumber(newExpanse.getUserId()));
        xml.AddElem("Date", date.convertToTrueDateFormat(newExpanse.getDate(), month));
        xml.AddElem("Item", newExpanse.getItem());
        xml.AddElem("Amount", auxiliaryMethods.convertFloatToString(newExpanse.getAmount()));
        xml.Save(NAME_OF_XML_FILE);
    }
    loadExpanses();
}
void ExpansesFile::loadExpanses() {

    Expanse expanse;

    if (xml.Load(NAME_OF_XML_FILE) == true) {
        xml.ResetMainPos();
        xml.FindElem("ExpansesFile");
        xml.IntoElem();

        while (xml.FindElem() == true) {

            expanse.setOperationId(auxiliaryMethods.changeIdToInteger(xml.GetTagName()));

            xml.FindChildElem("UserID");
            expanse.setUserId(auxiliaryMethods.changeIdToInteger(xml.GetChildData()));

            xml.FindChildElem("Date");
            expanse.setDate(date.convertTrueDateToInt(xml.GetChildData()));

            xml.FindChildElem("Item");
            expanse.setItem(xml.GetChildData());

            xml.FindChildElem("Amount");
            expanse.setAmount(auxiliaryMethods.convertToFloat(xml.GetChildData()));

            expanses.push_back(expanse);
        }
    }
    else {
        cout << "Expanses file does not exist! " << endl;
    }
}
vector <Expanse> ExpansesFile::getExpansesVector(){
    return expanses;
}
vector <Expanse> ExpansesFile::loadExpansesFromChoosenTime(int logedUserId,int secondChoosenDate,int firstChoosenDate) {

    Expanse choosenExpanse;
    vector <Expanse> choosenExpanses;

    if (xml.Load(NAME_OF_XML_FILE) == true) {
        xml.ResetPos();
        xml.FindElem("ExpansesFile");
        xml.IntoElem();

        while (xml.FindElem() == true) {

            choosenExpanse.setOperationId(auxiliaryMethods.changeIdToInteger(xml.GetTagName()));

            xml.FindChildElem("UserID");
            choosenExpanse.setUserId(0);
            if (auxiliaryMethods.changeIdToInteger(xml.GetChildData()) == logedUserId) {
                choosenExpanse.setUserId(auxiliaryMethods.changeIdToInteger(xml.GetChildData()));

                xml.FindChildElem("Date");
                choosenExpanse.setDate(0);
                if(date.convertTrueDateToInt(xml.GetChildData()) >= firstChoosenDate && date.convertTrueDateToInt(xml.GetChildData()) <= secondChoosenDate) {
                    choosenExpanse.setDate(date.convertTrueDateToInt(xml.GetChildData()));

            xml.FindChildElem("Item");
            choosenExpanse.setItem(xml.GetChildData());

            xml.FindChildElem("Amount");
            choosenExpanse.setAmount(auxiliaryMethods.convertToFloat(xml.GetChildData()));
                }
            }

            if (choosenExpanse.getUserId() != 0 && choosenExpanse.getDate() != 0){
                choosenExpanse.getItem();
                choosenExpanses.push_back(choosenExpanse);
            }
        }
    }
    else{
        cout << "No data. " << endl;
    }
    return choosenExpanses;
}

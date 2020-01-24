#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>
#include "xmlFile.h"
#include "Date.h"
#include "Income.h"
#include "Markup.h"

using namespace std;

class IncomesFile : public XmlFile{

    AuxiliaryMethods auxiliaryMethods;
    Date date;
    CMarkup xml;
    vector <Income> incomes;
public:
    IncomesFile(string nameOfFile) : XmlFile(nameOfFile) {
        loadIncomes();
    }
    void addIncome(Income newIncome, int month);
    void loadIncomes();
    vector <Income> loadIncomesFromChoosenTime(int logedUserId,int secondChoosenDate,int firstChoosenDate);
    vector <Income> getIncomesVector();
};

#endif

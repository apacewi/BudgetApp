#ifndef EXPANSESFILE_H
#define EXPANSESFILE_H

#include <iostream>
#include <vector>
#include "xmlFile.h"
#include "Date.h"
#include "Expanse.h"
#include "Markup.h"

using namespace std;

class ExpansesFile : public XmlFile{

    AuxiliaryMethods auxiliaryMethods;
    Date date;
    CMarkup xml;
    vector <Expanse> expanses;
public:
    ExpansesFile(string nameOfFile) : XmlFile(nameOfFile) {
        loadExpanses();
    }
    void addExpanse(Expanse newExpanse, int month);
    void loadExpanses();
    vector <Expanse> loadExpansesFromChoosenTime(int logedUserId,int secondChoosenDate,int firstChoosenDate);
    vector <Expanse> getExpansesVector();
};

#endif

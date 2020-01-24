#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include "AuxiliaryMethods.h"

using namespace std;

class XmlFile
{
protected:

    const string NAME_OF_XML_FILE;

public:
    XmlFile(string name) : NAME_OF_XML_FILE(name){}
};

#endif

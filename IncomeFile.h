#ifndef INCOMEFILE_H
#define INCOMEFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Markup.h"
#include "XmlFile.h"
#include "Item.h"
#include "AdditionalMethods.h"

using namespace std;

class IncomeFile : public XmlFile {

    string fileNameWithIncomes;
    int lastIncomeId;
    int idLoggedUser;

public:
    IncomeFile(string fileNameWithIncomes) : XmlFile(fileNameWithIncomes){
     idLoggedUser = 0;
     lastIncomeId = 0;
    };
    void addIncomeToFile(Item income);
    //int getFromFileLastItemId();
    vector <Item> getIncomeFromFile(int idLoggedUser);
    Item changeIntDateFormat(Item income);
};

#endif

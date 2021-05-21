#ifndef INCOMEFILE_H
#define INCOMEFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Markup.h"
#include "Item.h"
#include "AdditionalMethods.h"

using namespace std;

class IncomeFile {

    string FileNameWithIncomes;
    int lastIncomeId;
    int idLoggedUser;

public:
    IncomeFile();

    //IncomeFile(string FileNameWithIncomes) : XmlFile(FileNameWithIncomes){};
    void addIncomeToFile(Item income);
    //int getFromFileLastItemId();
    vector <Item> getIncomeFromFile(int idLoggedUser);
    Item changeIntDateFormat(Item income);
};

#endif
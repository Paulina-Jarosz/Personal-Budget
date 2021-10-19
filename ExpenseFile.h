#ifndef EXPENSEFILE_H
#define EXPENSEFILE_H
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Markup.h"
#include "XmlFile.h"
#include "Item.h"
#include "AdditionalMethods.h"

using namespace std;

class ExpenseFile : public XmlFile {

    string fileNameWithExpenses;
    int lastItemId;
    int idLoggedUser;
    vector <Item> expenses;

public:
    ExpenseFile(string FileNameWithExpenses) : XmlFile(FileNameWithExpenses){
     //idLoggedUser = 0;
     //lastItemId = 0;
    };
    void addExpenseToFile(Item expense);
    vector <Item> getExpenseFromFile(int idLoggedUser);
    //int getLastItemId();
};

#endif

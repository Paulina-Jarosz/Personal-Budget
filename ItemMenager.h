#ifndef ITEMMENAGER_H
#define ITEMMENAGER_H

#include <iostream>
#include <vector>

#include "Item.h"
#include "User.h"
#include "UserMenager.h"

using namespace std;

class ItemMenager : public Item {

    int incomeId;
    vector <Item> expenses;
    vector <Item> incomes;
    //IncomeFile incomeFile;

    Item provideItemDetails();
    int getNewItemId();

public:
    ItemMenager (int idLoggedUser){
    //items = incomeFile.getIncomeFromFile();
    };
    void addIncome(int idLoggedUser);


};
#endif

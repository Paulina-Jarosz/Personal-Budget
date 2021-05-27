#ifndef ITEMMENAGER_H
#define ITEMMENAGER_H

#include <iostream>
#include <vector>

#include "Item.h"
#include "User.h"
#include "UserMenager.h"
#include "DateMenager.h"
#include "IncomeFile.h"

using namespace std;

class ItemMenager : public Item {

    const int ID_LOGGED_USER;
    //vector <Item> items;
    //vector <Item> expenses;
    vector <Item> incomes;
    IncomeFile incomeFile;
    //int idLoggedUser;

    Item provideIncomeDetails();
    int getNewItemId();

public:
    ItemMenager (int idLoggedUser) : incomeFile(),ID_LOGGED_USER (idLoggedUser){
    //incomes = incomeFile.getIncomeFromFile(ID_LOGGED_USER);
    };
    void addIncome();
    bool provideDate();
    void showAllIncomes();

};
#endif

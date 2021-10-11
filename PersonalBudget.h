#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserMenager.h"
#include "ItemMenager.h"
#include "DateMenager.h"

using namespace std;

class PersonalBudget {

    UserMenager userMenager;
    ItemMenager *itemMenager;
    //const FILE_NAME_WITH_USERS;
    const string FILE_NAME_WITH_INCOMES;
    const string FILE_NAME_WITH_EXPENSES;

public:
    PersonalBudget(string fileNameWithUsers, string FileNameWithIncomes, string FileNameWithExpenses)
    : userMenager(fileNameWithUsers), FILE_NAME_WITH_INCOMES(FileNameWithIncomes), FILE_NAME_WITH_EXPENSES (FileNameWithExpenses) {
        itemMenager = NULL;
    }
    ~PersonalBudget() {
        delete itemMenager;
        itemMenager = NULL;
    };

    char chooseOptionFromMainMenu();
    void userRegistration();
    void showAllUsers();
    bool ifUserIsLogged();
    int userLogIn();
    void logOffUser();
    char chooseOptionFromUserMenu();
    void addIncome();

};


#endif

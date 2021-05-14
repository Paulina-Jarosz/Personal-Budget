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

public:
    PersonalBudget()
    : userMenager() {
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
    void addIncome(int idLoggedUser);

};


#endif

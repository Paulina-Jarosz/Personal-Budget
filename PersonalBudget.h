#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserMenager.h"

using namespace std;

class PersonalBudget {

    UserMenager userMenager;

public:
    char chooseOptionFromMainMenu();
    void userRegistration();
    void showAllUsers();
    bool ifUserIsLogged();
    void userLogIn();

};


#endif

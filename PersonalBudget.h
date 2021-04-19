#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserMenager.h"

using namespace std;

class PersonalBudget {

    UserMenager userMenager;

public:
    void userRegistration();
    void showAllUsers();

};


#endif

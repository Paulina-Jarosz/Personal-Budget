#ifndef USERMENAGER_H
#define USERMENAGER_H

#include <iostream>
#include <vector>

//#include "FileWithUsers.h"
#include "User.h"


using namespace std;

class UserMenager{

    int idLoggedUser;
    vector <User> users;

    User provideNewUserData();
    int getNewUserId();
    bool isLoginExist(string login);

public:
    void userRegistration();
    void showAllUsers();

};


#endif

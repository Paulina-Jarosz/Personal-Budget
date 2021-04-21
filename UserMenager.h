#ifndef USERMENAGER_H
#define USERMENAGER_H

#include <iostream>
#include <vector>

#include "FileWithUsers.h"
#include "User.h"
#include "AdditionalMethods.h"


using namespace std;

class UserMenager{

    int idLoggedUser;
    vector <User> users;
    FileWithUsers fileWithUsers;

    User provideNewUserData();
    int getNewUserId();
    bool isLoginExist(string login);

public:
    UserMenager (){
    idLoggedUser = 0;
    users = fileWithUsers.loadUserFromFile();
    };
    void userRegistration();
    void showAllUsers();
    bool ifUserIsLogged();
    int getIdLoggedUser();
    int userLogIn();
    void logOffUser();
    char chooseOptionFromUserMenu();

};


#endif

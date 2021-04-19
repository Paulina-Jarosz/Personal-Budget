#include "UserMenager.h"

void UserMenager :: userRegistration()
{
    User user = provideNewUserData();
    FileWithUsers fileWithUsers;
    users.push_back(user);
    fileWithUsers.addUserToFile(user);
    cout << endl << "Account created" << endl << endl;
    system("pause");
}

User UserMenager :: provideNewUserData()
{
    User user;

    user.setupUserId(getNewUserId());
    string login, userName, userSurname;
    do
    {
        cout << "Provide login: ";
        cin >> login;
        user.setupLogin(login);
    } while (isLoginExist(user.getLogin()) == true);

    string password;
    cout << "Provide password: ";
    cin >> password;
    user.setupPassword(password);
    cout << "Provide name: ";
    cin >> userName;
    user.setupUserName(userName);
    cout << "Provide surname: ";
    cin >> userSurname;
    user.setupUserSurname(userSurname);

    return user;
}

int UserMenager :: getNewUserId()
{
        if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;

}

bool UserMenager :: isLoginExist(string login)
{
    for (int i = 0; i < users.size(); i++){

        if (users[i].getLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
             return true;
        }
    }
    return false;
}

void UserMenager :: showAllUsers() {

    for (int i = 0; i < users.size(); i++) {
        cout<< users[i].getUserId() << endl;
        cout<< users[i].getLogin() << endl;
        cout<< users[i].getPassword() << endl;
        cout<< users[i].getUserName() << endl;
        cout<< users[i].getUserSurname() << endl;
    }
}

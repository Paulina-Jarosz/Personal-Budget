#include "PersonalBudget.h"

char PersonalBudget ::chooseOptionFromMainMenu()
{
    char choose;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Login" << endl;
    cout << "9. End " << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choose = AdditionalMethods :: getCharacter();

    return choose;
}

void PersonalBudget :: userRegistration() {

    userMenager.userRegistration();
}

void PersonalBudget :: showAllUsers() {

    userMenager.showAllUsers();
}

bool PersonalBudget :: ifUserIsLogged(){
    userMenager.ifUserIsLogged();
}

int PersonalBudget :: userLogIn() {

    userMenager.userLogIn();
    if (userMenager.ifUserIsLogged())
    {
        itemMenager = new ItemMenager (userMenager.getIdLoggedUser());
    }
}

void PersonalBudget :: logOffUser(){
    userMenager.logOffUser();
    delete itemMenager;
    itemMenager = NULL;
}

char PersonalBudget :: chooseOptionFromUserMenu(){
    userMenager.chooseOptionFromUserMenu();
}

void PersonalBudget :: addIncome(int idLoggedUser) {

    itemMenager->addIncome(idLoggedUser);
}

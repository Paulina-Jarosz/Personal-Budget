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
    cout << "Your choice ";
    //choose = AdditionalMethods :: getCharacter();

    return choose;
}

void PersonalBudget :: userRegistration() {

    userMenager.userRegistration();
}

void PersonalBudget :: showAllUsers() {

    userMenager.showAllUsers();
}

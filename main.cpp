#include <iostream>
#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget;
    char choose = 0;

         while (true)
    {
        if (personalBudget.ifUserIsLogged() == false)
        {
            choose = personalBudget.chooseOptionFromMainMenu();

            switch (choose)
            {
            case '1':
                personalBudget.userRegistration();
                break;
            case '2':
                personalBudget.userLogIn();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }
    //personalBudget.showAllUsers();
    return 0;
}

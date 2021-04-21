#include <iostream>
#include "PersonalBudget.h"

using namespace std;

int main() {
    PersonalBudget personalBudget;
    char choose = 0;
    int idLoggedUser =0;

    while (true) {
        if (personalBudget.ifUserIsLogged() == false) {
            choose = personalBudget.chooseOptionFromMainMenu();

            switch (choose) {
            case '1':
                personalBudget.userRegistration();
                break;
            case '2':
                idLoggedUser = personalBudget.userLogIn();
                if( idLoggedUser != 0)

                    choose = personalBudget.chooseOptionFromUserMenu();

                switch (choose) {
                case '1':
                    //personalBudget.addIncome();
                    break;
                case '2':
                    //personalBudget.addExpense();
                    break;
                case '3':
                    //personalBudget.displayBalanceForCurrentMonth();
                    break;
                case '4':
                    //personalBudget.displayBalanceForPreviousMonth();
                    break;
                case '5':
                    //personalBudget.displayBalanceForSelectedPeriod();
                    break;
                case '6':
                    //personalBudget.changePasswordLoggedUser();
                    break;
                case '7':
                    personalBudget.logOffUser();
                    //item.clear();
                    break;
                }
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

#include "ItemMenager.h"

void ItemMenager :: addIncome()
{
    Item income = provideIncomeDetails();
    incomes.push_back(income);
    incomeFile.addIncomeToFile(income);
    cout << endl << "Income added to the file" << endl << endl;
    system("pause");
}

int ItemMenager :: getNewItemId()
{
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getItemId() + 1;
}

Item ItemMenager :: provideIncomeDetails()
{
    Item item;
    DateMenager dateMenager;
    string itemName, userSurname, otherDate, stringDatewithoutDash;
    int currentDate, intDateWithoutDash;
    float amount;
    char choice;

    int itemId = getNewItemId();
    item.setupItemId(itemId);
    item.setupUserId(idLoggedUser);

    cout << "Do you wnat to add income with current date?" <<endl;
    cout << "If yes, please click 'y', if you want to chose other date, please click 'n': " << endl;
    choice = AdditionalMethods :: getCharacter();

    if (choice == 'y') {
        currentDate = dateMenager.getCurrentDate();
        //currentStringDate = AdditionalMethods :: convertIntToString(currentDate);
        //cout << "Current date: " << currentDate << endl;
        item.setupDate(currentDate);
    }

    else if (choice == 'n') {
        cout << "Provide date in format YYYY-MM-DD: ";
        do {
            otherDate = AdditionalMethods :: loadLine();
        } while (dateMenager.isDateCorrect(otherDate) == false);
        stringDatewithoutDash = AdditionalMethods :: removeDashFromDate(otherDate);
        intDateWithoutDash = AdditionalMethods :: convertStringToInt (stringDatewithoutDash);
        item.setupDate(intDateWithoutDash);
    }
    cout << "Provide income description: ";
    itemName = AdditionalMethods :: loadLine();
    item.setupItemName(itemName);
    cout << "Provide amount: ";
    amount = AdditionalMethods :: loadFloat();
    item.setupItemAmount(amount);

    return item;
}

void ItemMenager :: showAllIncomes() {

    for (int i = 0; i < incomes.size(); i++) {
        cout << "Item Id: " << incomes[i].getItemId() << endl;
        cout << "User Id: " << incomes[i].getUserId() << endl;
        cout << "Item date: " << incomes[i].getItemDate() << endl;
        cout << "Item name: " << incomes[i].getItemName() << endl;
        cout << "Item amount: " << incomes[i].getItemAmount() << endl << endl;
    }
}

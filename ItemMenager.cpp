#include "ItemMenager.h"

void ItemMenager :: addIncome()
{
    Item income = provideIncomeDetails();
    incomes.push_back(income);
    incomeFile.addIncomeToFile(income);
    cout << endl << "Income added to the file" << endl << endl;
    showAllIncomes();
    system("pause");
}

void ItemMenager :: addExpense()
{
    Item expense = provideExpenseDetails();
    expenses.push_back(expense);
    expenseFile.addExpenseToFile(expense);
    cout << endl << "Expense added to the file" << endl << endl;
    showAllExpenses();
    system("pause");
}

int ItemMenager :: getNewIncomeId()
{
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getItemId() + 1;
}

int ItemMenager :: getNewExpenseId()
{
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().getItemId() + 1;
}

Item ItemMenager :: provideIncomeDetails()
{
    Item item;
    DateMenager dateMenager;
    string itemName, userSurname, otherDate, stringDatewithoutDash, currentStringDate, stringAmount;
    int currentDate, intDateWithoutDash;
    float amount;
    char choice;

    int itemId = getNewIncomeId();
    item.setupItemId(itemId);
    item.setupUserId(ID_LOGGED_USER);

    cout << "Do you want to add income with current date?" <<endl;
    cout << "If yes, please click 'y', if you want to chose other date, please click 'n': " << endl;
    choice = AdditionalMethods :: getCharacter();

    if (choice == 'y') {
        currentDate = dateMenager.getCurrentDate();
        currentStringDate = AdditionalMethods :: convertIntToString(currentDate);
        currentStringDate = AdditionalMethods :: addDashToDate (currentStringDate);
        item.setupStringDate(currentStringDate);
    }
    else if (choice == 'n') {

        do {
            cout << "Provide date in format YYYY-MM-DD: ";
            //cout << "Incorrect date or format! Please enter again" << endl;
            otherDate = AdditionalMethods :: loadLine();
        } while (dateMenager.isDateCorrect(otherDate) == false);
        stringDatewithoutDash = AdditionalMethods :: removeDashFromDate(otherDate);
        intDateWithoutDash = AdditionalMethods :: convertStringToInt (stringDatewithoutDash);
        item.setupStringDate(otherDate);
    }
    cout << "Provide income description: ";
    itemName = AdditionalMethods :: loadLine();
    item.setupItemName(itemName);
    cout << "Provide amount: ";
    amount = AdditionalMethods :: loadFloat();
    item.setupItemAmount(amount);

    return item;
}

Item ItemMenager :: provideExpenseDetails()
{
    Item item;
    DateMenager dateMenager;
    string itemName, userSurname, otherDate, stringDatewithoutDash, currentStringDate, stringAmount;
    int currentDate, intDateWithoutDash;
    float amount;
    char choice;

    int itemId = getNewExpenseId();
    item.setupItemId(itemId);
    item.setupUserId(ID_LOGGED_USER);

    cout << "Do you want to add expense with current date?" <<endl;
    cout << "If yes, please click 'y', if you want to chose other date, please click 'n': " << endl;
    choice = AdditionalMethods :: getCharacter();

    if (choice == 'y') {
        currentDate = dateMenager.getCurrentDate();
        currentStringDate = AdditionalMethods :: convertIntToString(currentDate);
        currentStringDate = AdditionalMethods :: addDashToDate (currentStringDate);
        item.setupStringDate(currentStringDate);
    }
    else if (choice == 'n') {

        do {
            cout << "Provide date in format YYYY-MM-DD: ";
            //cout << "Incorrect date or format! Please enter again" << endl;
            otherDate = AdditionalMethods :: loadLine();
        } while (dateMenager.isDateCorrect(otherDate) == false);
        stringDatewithoutDash = AdditionalMethods :: removeDashFromDate(otherDate);
        intDateWithoutDash = AdditionalMethods :: convertStringToInt (stringDatewithoutDash);
        item.setupStringDate(otherDate);
    }
    cout << "Provide expense description: ";
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

void ItemMenager :: showAllExpenses() {

    for (int i = 0; i < expenses.size(); i++) {
        cout << "Item Id: " << expenses[i].getItemId() << endl;
        cout << "User Id: " << expenses[i].getUserId() << endl;
        cout << "Item date: " << expenses[i].getItemDate() << endl;
        cout << "Item name: " << expenses[i].getItemName() << endl;
        cout << "Item amount: " << expenses[i].getItemAmount() << endl << endl;
    }
}

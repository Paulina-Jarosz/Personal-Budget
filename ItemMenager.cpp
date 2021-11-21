#include "ItemMenager.h"

void ItemMenager :: addIncome()
{
    Item income = provideIncomeDetails();
    incomes.push_back(income);
    incomeFile.addIncomeToFile(income);
    cout << endl << "Income added to the file" << endl << endl;
    //showAllIncomes(income); //usunac jak kod bedzie ok
    system("pause");
}

void ItemMenager :: addExpense()
{
    Item expense = provideExpenseDetails();
    expenses.push_back(expense);
    expenseFile.addExpenseToFile(expense);
    cout << endl << "Expense added to the file" << endl << endl;
    //showAllExpenses(expense); // usunac jak kod bedzie ok
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


void ItemMenager :: showAllIncomes(Item income) {

    //for (int i = 0; i < incomes.size(); i++) {
        cout << "Item Id: " << income.getItemId() << endl;
        cout << "User Id: " << income.getUserId() << endl;
        //cout << "Item date: " << income.getItemDate() << endl;
        string iteamStringDate = AdditionalMethods :: convertIntToString (income.getIntDate());
        string dateItemWithDash = AdditionalMethods :: addDashToDate(iteamStringDate);
        cout << "Item date: " << dateItemWithDash << endl;
        cout << "Item name: " << income.getItemName() << endl;
        cout << "Item amount: " << income.getItemAmount() << endl << endl;
    //}
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

void ItemMenager :: displayIncomeBalance(){

    if (!incomes.empty()) {
        cout << "             >>> Incomes: <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Item> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            if (itr -> getUserId() == ID_LOGGED_USER) {
                showAllIncomes(*itr);
            }
            cout << endl;
        }
    }
    else {
        cout << endl << "There is no incomes" << endl << endl;
    }
    //quicksort(incomes,  0, incomes.size()-1);
}

void ItemMenager :: displayBalanceForCurrentMonth(){

    displayIncomeBalance();
    quicksort(incomes,  0, incomes.size()-1);
    system("pause");
    //quicksort(incomes,  0, incomes.size()-1);
    //sortowanie(incomes);

}

void ItemMenager :: showAllIncomesInOrder (vector<Item>incomes) {

    cout <<"AFTER SORTING BY DATE: " <<endl << endl;
    for (int i = 0; i < incomes.size(); i++) {
        cout << "Item Id: " << incomes[i].getItemId() << endl;
        cout << "User Id: " << incomes[i].getUserId() << endl;
        string iteamStringDate = AdditionalMethods :: convertIntToString (incomes[i].getIntDate());
        string dateItemWithDash = AdditionalMethods :: addDashToDate(iteamStringDate);
        cout << "Item date: " << dateItemWithDash << endl;
        //cout << "Item date: " << incomes[i].getItemDate() << endl;
        cout << "Item name: " << incomes[i].getItemName() << endl;
        cout << "Item amount: " << incomes[i].getItemAmount() << endl << endl;
    }
    system("pause");
}

void ItemMenager :: quicksort(vector<Item>incomes, int left, int right)
{
    Item v = incomes[(left + right)/2];
    Item x;
    int i,j;
    i=left;
    j=right;
    do
    {
        while (incomes[i].getIntDate() < v.getIntDate()) i++;
        while (incomes[j].getIntDate() > v.getIntDate()) j--;
        if (i<=j)
        {
            x=incomes[i];
            incomes[i]=incomes[j];
            incomes[j]=x;
            i++;
            j--;
        }
    }
    while (i<=j);
    if (j>left) quicksort(incomes,left, j);
    if (i<right) quicksort(incomes, i, right);

    showAllIncomesInOrder (incomes);
    //return incomes;
}


/*void ItemMenager :: sortowanie(vector<Item>incomes){

    sort(incomes.begin(), incomes.end(), sortByDate());
    showAllIncomesInOrder (incomes);
}*/

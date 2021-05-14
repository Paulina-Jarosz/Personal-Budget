#include "ItemMenager.h"

void ItemMenager :: addIncome(int idLoggedUser)
{
<<<<<<< HEAD
    if (provideDate() == true){
    Item income = provideItemDetails();
=======
    Item income = provideIncomeDetails();
>>>>>>> feature_create_date_class
    //FileWithUsers fileWithUsers;
    incomes.push_back(income);
    //fileWithUsers.addItemToFile(income);
    cout << endl << "Icome added to the file" << endl << endl;
    system("pause");
    }
    else cout <<"Incorrect date!" <<endl;
}

int ItemMenager :: getNewItemId()
{
    if (items.empty() == true)
        return 1;
    else
        return items.back().getItemId() + 1;
}

<<<<<<< HEAD
bool ItemMenager :: provideDate (){
    DateMenager dateMenager;
    string date;

    cout << "Provide date in format YYYY-MM-DD: ";
    cin >> date;
    if (dateMenager.isDateCorrect(date) == true){
        return true;
    }
    else return false;

}
Item ItemMenager :: provideItemDetails()
{
    Item item;
    string itemName, userSurname;
=======
Item ItemMenager :: provideIncomeDetails()
{
    Item item;
    DateMenager dateMenager;
    string itemName, userSurname, otherDate, stringDatewithoutDash;
    int currentDate, intDateWithoutDash;
>>>>>>> feature_create_date_class
    float amount;
    char choice;

<<<<<<< HEAD
    if (provideDate() == true){
    item.setupItemId(getNewItemId());
    cout << "Provide income description: ";
    cin >> itemName;
    item.setupItemName(itemName);
    cout << "Provide amount: ";
    cin >> amount;
    amount = AdditionalMethods :: loadFloat();
    item.setupItemAmount(amount);

    return item;
=======
    cout << "Do you wnat to add income with current date?" <<endl;
    cout << "If yes, please click 'y', if you want to chose other date, please click 'n': " << endl;
    choice = AdditionalMethods :: getCharacter();

    if (choice == 'y')
    {
       currentDate = dateMenager.getCurrentDate();
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

        cout << "Provide income description: ";
        itemName = AdditionalMethods :: loadLine();
        item.setupItemName(itemName);
        cout << "Provide amount: ";
        amount = AdditionalMethods :: loadFloat();
        item.setupItemAmount(amount);

        return item;
    } else {
        cout << "This was incorect character" << endl;
>>>>>>> feature_create_date_class
    }

}


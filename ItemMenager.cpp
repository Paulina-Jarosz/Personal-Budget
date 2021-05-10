#include "ItemMenager.h"

void ItemMenager :: addIncome(int idLoggedUser)
{
    if (provideDate() == true){
    Item income = provideItemDetails();
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
    float amount;

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
    }

}


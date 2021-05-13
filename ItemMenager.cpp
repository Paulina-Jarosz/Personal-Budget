#include "ItemMenager.h"

void ItemMenager :: addIncome(int idLoggedUser)
{
    Item income = provideItemDetails();
    //FileWithUsers fileWithUsers;
    incomes.push_back(income);
    //fileWithUsers.addItemToFile(income);
    cout << endl << "Icome added to the file" << endl << endl;
    system("pause");
}

int ItemMenager :: getNewItemId()
{
    if (items.empty() == true)
        return 1;
    else
        return items.back().getItemId() + 1;
}

Item ItemMenager :: provideItemDetails()
{
    Item item;
    string itemName, date, userSurname;
    float amount;

    item.setupItemId(getNewItemId());
    //item.(UserMenager :: getIdLoggedUser());
    /*do
    {
        cout << "Provide login: ";
        cin >> login;
        user.setupLogin(login);
    } while (isLoginExist(user.getLogin()) == true);*/

    cout << "Provide income description: ";
    cin >> itemName;
    item.setupItemName(itemName);
    cout << "Provide amount: ";
    cin >> amount;
    amount = AdditionalMethods :: loadFloat();
    item.setupItemAmount(amount);
    cout << "Provide date in format YYYY-MM-DD: ";
    cin >> date;
    //item.setupDate(date);

    return item;
}


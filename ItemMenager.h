#ifndef ITEMMENAGER_H
#define ITEMMENAGER_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Item.h"
#include "User.h"
#include "UserMenager.h"
#include "DateMenager.h"
#include "IncomeFile.h"
#include "ExpenseFile.h"

using namespace std;

class ItemMenager : public Item {

    struct intDate {
        int intDateToSort;
    };


    const int ID_LOGGED_USER;
    //vector <Item> items;
    vector <Item> expenses;
    vector <Item> incomes;
    IncomeFile incomeFile;
    ExpenseFile expenseFile;
    int idLoggedUser;

    Item provideIncomeDetails();
    Item provideExpenseDetails();
    int getNewIncomeId();
    int getNewExpenseId();

public:
    ItemMenager (string fileNameWithIncomes, string fileNameWithExpenses, int idLoggedUser) : incomeFile (fileNameWithIncomes),expenseFile (fileNameWithExpenses),ID_LOGGED_USER(idLoggedUser){
    //ItemMenager (int idLoggedUser) : incomeFile(),ID_LOGGED_USER (idLoggedUser){
    incomes = incomeFile.getIncomeFromFile(ID_LOGGED_USER);
    expenses = expenseFile.getExpenseFromFile(ID_LOGGED_USER);
    };

    void addIncome();
    void addExpense();
    bool provideDate();
    void showAllIncomes(Item income);// usunac jak kod bedzie skonczony
    void showAllExpenses(); //usunac jak kod bedzie skonczony
    void displayBalanceForCurrentMonth();
    void quicksort(vector<Item> incomes, int first, int second);
    void showAllIncomesInOrder(vector<Item> incomes);
    //void sortowanie(vector<Item>incomes);

    /*struct sortByDate
    {
        inline bool operator() (intDate& firstDate, intDate& secondDate) {
            return (firstDate.getIntDate() < secondDate.getIntDate());
        }
    };*/
};
#endif

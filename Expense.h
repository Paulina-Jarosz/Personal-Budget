#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

#include "Item.h"

using namespace std;

class Expense : public Item {

    int expenseId;

public:
    void setupExpenseId (int newExpenseId);

};
#endif

#ifndef INCOME_H
#define INCOME_H

#include <iostream>

#include "Item.h"

using namespace std;

class Income : public Item {

    int incomeId;

public:
    void setupIncomeId (int newIncomeId);


};
#endif

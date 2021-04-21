#ifndef ITEM_H
#define ITEM_H

#include <iostream>

using namespace std;

class Item {
    string itemName;
    float itemAmount;

public:
    //void setupDate();
    void setupItemName(string newItemName);
    void setupItemAmount(float newItemAmount);
    string getItemName();
    float getItemAmount();
    //string getSelectedPeriod();
    //void sortByDateFromOldest(); // vector?


};

#endif

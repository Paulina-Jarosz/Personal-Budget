#ifndef ITEM_H
#define ITEM_H

#include <iostream>

using namespace std;

class Item {
    int itemId;
    string itemName;
    float itemAmount;

public:
    //void setupDate();
    void setupItemId (int newItemId);
    void setupItemName(string newItemName);
    void setupItemAmount(float newItemAmount);
    int getItemId();
    string getItemName();
    float getItemAmount();
    //string getSelectedPeriod();
    //void sortByDateFromOldest(); // vector?


};

#endif

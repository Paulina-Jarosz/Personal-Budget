#ifndef ITEM_H
#define ITEM_H

#include <iostream>

using namespace std;

class Item {
    int itemId;
    string itemName;
    float itemAmount;
    string itemDate;

public:
    //void setupDate();
    void setupItemId (int newItemId);
    void setupItemName(string newItemName);
    void setupItemAmount(float newItemAmount);
    void setupDate (string newDate);
    int getItemId();
    string getItemName();
    float getItemAmount();
    //string getSelectedPeriod();
    //void sortByDateFromOldest(); // vector?


};

#endif

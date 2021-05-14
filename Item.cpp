#include "Item.h"

void Item :: setupDate (int newDate) {
    if (newDate >= 0)
        itemDate = newDate;
}
void Item :: setupItemId (int newItemId) {
    if (newItemId >= 0)
        itemId = newItemId;
}

void Item :: setupItemName (string newItemName) {
        itemName = newItemName;
}

void Item :: setupItemAmount (float newItemAmount) {
        itemAmount = newItemAmount;
}
int Item :: getItemId() {
    return itemId;
}

string Item :: getItemName() {
    return itemName;
}

float Item :: getItemAmount() {
    return itemAmount;
}


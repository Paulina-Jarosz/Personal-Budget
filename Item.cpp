#include "Item.h"

void Item :: setupItemName (string newItemName) {
        itemName = newItemName;
}

void Item :: setupItemAmount (float newItemAmount) {
        itemAmount = newItemAmount;
}

string Item :: getItemName() {
    return itemName;
}

float Item :: getItemAmount() {
    return itemAmount;
}

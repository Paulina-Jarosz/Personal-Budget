#ifndef ADDITIONALMETHODS_H
#define ADDITIONALMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AdditionalMethods {

public:
    static char getCharacter();
    static string changeFirstLetterToCapitalAndOtherToLowercase(string text);
    static string getNumber(string text, int characterPosition);
    static float loadFloat();
    static int  convertStringToInt(string number);
    static string convertIntNaString(int number);

};

#endif

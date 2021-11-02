#ifndef ADDITIONALMETHODS_H
#define ADDITIONALMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

class AdditionalMethods {

public:
    static char getCharacter();
    static string changeFirstLetterToCapitalAndOtherToLowercase(string text);
    static string getNumber(string text, int characterPosition);
    static float loadFloat();
    static string loadLine();
    static int  convertStringToInt(string number);
    static string convertIntToString(int number);
    static string addDashToDate (string date);
    static string removeDashFromDate (string date);
    static string convertFloatToString (float amount);
    static string changeCommaToDot(string amount);

};

#endif

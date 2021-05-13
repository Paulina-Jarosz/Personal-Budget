#ifndef DATEMENAGER_H
#define DATEMENAGER_H

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <windows.h>

#include "Date.h"

using namespace std;

class DateMenager{

    Date dateOb;

    const int MAX_VALID_YR = 2021;  //current month?
    const int MIN_VALID_YR = 2000; //2000-01-01

    bool isLeap(int year);

public:
    int convertStringDateToInt(string date);
    Date divideDate(string date);

    string currentDate();
    int countDays(string month, string year);
    void showDate(Date dateOb);
    bool isValidYear(int year);
    bool isValidMonth (int month);
    void isValidFormatDate(string date);
    bool isValidDate(Date dateOb);
    bool isValidDay (int dayConverted, int monthConverted, int yearConverted);
    bool isDateCorrect(string date);


};

#endif

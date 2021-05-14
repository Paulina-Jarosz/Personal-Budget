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

<<<<<<< HEAD
    Date dateOb;

    const int MAX_VALID_YR = 2021;  //current month?
=======
    time_t calculatedTime;
    struct tm * data;
    int year, month, day;

>>>>>>> feature_create_date_class
    const int MIN_VALID_YR = 2000; //2000-01-01

    bool isLeap(int year);

public:
<<<<<<< HEAD
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

=======
    int getCurrentDate();
    int getCurrentYear();
    int getCurrentMonth();
    int getCurrentDay();

    bool isDateCorrect (string date);
    bool isValidYear(int year);
    bool isValidMonth (int month);
    bool isValidDay (int dayConverted, int monthConverted, int yearConverted);
    bool isValidFormatDate(string date);

    void showDate(Date dateOb);
>>>>>>> feature_create_date_class

};

#endif

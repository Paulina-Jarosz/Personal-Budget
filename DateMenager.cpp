#include "DateMenager.h"

<<<<<<< HEAD
bool DateMenager :: isDateCorrect (string date){

    Date dateOb = divideDate(date);
    if (isValidDate(dateOb) == true){
            return true;
    }
    else return false;
}

Date DateMenager :: divideDate(string date){

    Date dateOb;
    string day, month, year;
    string dateDivided = "";
    int countNum =1;

    for (int i = 0 ; i <= date.length(); i++) {
        if (date[i] != '-') {
            dateDivided += date[i];
        } else {
            switch(countNum) {
            case 1:
                dateOb.setYear(dateDivided);
                break;
            case 2:
                dateOb.setMonth(dateDivided);
                break;
            }
            dateDivided = "";
            countNum++;
        }
        if (date[i] != ' ' ) {
            dateOb.setDay(dateDivided);
        } else cout << "incorrect date"<<endl;
    }
    showDate(dateOb);
    return dateOb;
}

int DateMenager :: convertStringDateToInt(string date)
{
    int numberInt;
    istringstream iss(date);
    iss >> numberInt;

    return numberInt;
=======
int DateMenager :: getCurrentDate() {
    int currentDate = 0;
    year = getCurrentYear();
    currentDate = (year * 10000);
    month = getCurrentMonth();
    currentDate += (month * 100);
    day = getCurrentDay();
    currentDate += day;

    return currentDate;
}

int DateMenager :: getCurrentYear() {
    time(&calculatedTime);
    data = localtime(&calculatedTime);
    year = data -> tm_year+1900;

    return year;
}

int DateMenager :: getCurrentMonth() {
    time(&calculatedTime);
    data = localtime(&calculatedTime);
    month = data -> tm_mon+1;

    return month;
}

int DateMenager :: getCurrentDay() {
    time(&calculatedTime);
    data = localtime(&calculatedTime);
    day = data -> tm_mday;

    return day;
}

bool DateMenager :: isDateCorrect(string date) {

    int year = (date[0]-'0')*1000 + (date[1]-'0')*100 + (date[2]-'0')*10 + (date[3]-'0');
    int month = (date[5]-'0')*10 + (date[6]-'0');
    int day = (date[8]-'0')*10 + (date[9]-'0');

    if (isValidFormatDate(date) == false) {
        return false;
    } else if (isValidYear (year) == false) {
        return false;
    } else if (isValidMonth(month) == false || month > getCurrentMonth()) {
        return false;
    } else if (day >= 1 && day <= 31) {
        if (isValidDay(day, month, year) == true) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }

    return true;
>>>>>>> feature_create_date_class
}

bool DateMenager :: isValidYear (int year) {

<<<<<<< HEAD
    if (year > MAX_VALID_YR || year < MIN_VALID_YR) {
=======
    if (year > getCurrentYear() || year < MIN_VALID_YR) {
>>>>>>> feature_create_date_class
        return false;
    }
    return true;
}

bool DateMenager :: isValidMonth(int month) {
    if (month < 1 || month > 12) {
        return false;
    }
    return true;
}

<<<<<<< HEAD
bool DateMenager :: isValidDay (int dayConverted, int monthConverted, int yearConverted) {

    if (monthConverted == 2) {
        if ((isLeap(yearConverted) == true) && (dayConverted == 29)) {
            //if (dayConverted >= 1 && dayConverted <= 29)
                return true;
        } else if (dayConverted >= 1 && dayConverted <= 28)
        {
            return true;
        }
        else if (dayConverted < 1 && dayConverted >= 30)
        {
=======
bool DateMenager :: isValidDay (int day, int month, int year) {

    if (month == 2) {
        if ((isLeap(year) == true) && (day == 29)) {
            return true;
        } else if (day >= 1 && day <= 28) {
            return true;
        } else if (day < 1 && day >= 30) {
>>>>>>> feature_create_date_class
            return false;
        }
    }

<<<<<<< HEAD
    else if (monthConverted == 4 || monthConverted == 6 ||
             monthConverted == 9 || monthConverted == 11) {
        if (dayConverted >= 1 && dayConverted <= 30) {
=======
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day >= 1 && day <= 30) {
>>>>>>> feature_create_date_class
            return true;
        } else return false;
    }
}

<<<<<<< HEAD
bool DateMenager :: isValidDate(Date dateOb)
{
    string year = dateOb.getYear();
    string month = dateOb.getMonth();
    string day = dateOb.getDay();
    int monthConverted = convertStringDateToInt(month);
    int yearConverted = convertStringDateToInt(year);
    int dayConverted = convertStringDateToInt(day);

    if (isValidYear (yearConverted) == false) {
        return false;
    } else if (isValidMonth(monthConverted) == false) {
        return false;
    } else if (dayConverted >= 1 && dayConverted <= 31) {
        if (isValidDay(dayConverted,monthConverted,monthConverted) == true) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

=======
bool DateMenager :: isValidFormatDate (string date) {

    if ((!date.size() == 10) || (!date[0] == 1) || (date[4] != '-') || (date[7] != '-'))
        return false;
    else
        return true;
}


>>>>>>> feature_create_date_class
bool DateMenager :: isLeap(int year) {
    if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
        return true;
    } else return false;
}

<<<<<<< HEAD
string DateMenager :: currentDate(){
  time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer,80,"%Y-%m-%d",timeinfo);
  std::string str(buffer);

  std::cout << str;
  return str;
}

=======
>>>>>>> feature_create_date_class
void DateMenager :: showDate(Date dateOb)
{
    cout << endl << "Rok: " << dateOb.getYear() << endl;
    cout << "miesiac: " << dateOb.getMonth() << endl;
    cout << "dzien: " << dateOb.getDay() << endl;
}
